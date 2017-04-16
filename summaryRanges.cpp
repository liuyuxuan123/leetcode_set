#include <iostream>
#include <set>
#include <vector>
using namespace std;


void printVec(const vector<string>& vec){
    for(auto it : vec){
        cout << it << " " << ends;
    }
    cout << endl;
}

vector<string> summaryRanges(vector<int>& nums){
    set<int> range(nums.begin(),nums.end());
    vector<pair<int,int>> rangePair;

    for(int i = 0;i < nums.size();i++){
        int right = nums[i];
        int left  = nums[i];

        bool isINTMAX = false;
        bool isINTMIN = false;

        if(range.find(nums[i]) != range.end()){
            while(right != INT_MAX && range.find(++right) != range.end()){
                range.erase(right);
            }

            while(left != INT_MIN && range.find(--left) != range.end()){
                range.erase(left);
            }

            if(right == INT_MAX){
                isINTMAX = true;
            }
            if(left == INT_MIN){
                isINTMIN = true;
            }

            if(isINTMAX && isINTMAX){
                rangePair.push_back(make_pair(left,right));
            }else if(isINTMAX){
                rangePair.push_back(make_pair(++left,right));
            }else if(isINTMIN){
                rangePair.push_back(make_pair(left,--right));
            }else{
                rangePair.push_back(make_pair(++left,--right));
            }
        }
    }

    vector<string> res;
    char t[256];

    for(int i = 0;i < rangePair.size();i++){
        if(rangePair[i].first != rangePair[i].second){
            int index = sprintf(t,"%d",rangePair[i].first);
            int index1 = sprintf(t + index,"%s","->");
            int index2 = sprintf(t + index + index1,"%d",rangePair[i].second);

            string s(t);
            memset(t,'\0',sizeof(t));
            res.push_back(s);
        }else{
            int index = sprintf(t,"%d",rangePair[i].first);
            string s(t);
            memset(t,'\0',sizeof(t));
            res.push_back(s);
        }
    }
    return res;
}

int main(){
    vector<int> sampleInput = {
        1,2,3,4,5,7,9,11
    };
    auto iter = summaryRanges(sampleInput);
    printVec(iter);
    return 0;
}
