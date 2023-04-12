    //输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
    //序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
    //此解法为暴力枚举
    #include<bits/stdc++.h>
    using namespace std;
    vector<vector<int>> findContinuousSequence(int target) {
        //想要是连续正整数数列，则数字最大为target的一半，向上取整
        int mid = ceil(target/2);
        vector<int>dq;
        vector<vector<int>>res;
        int sum = 0;
        for(int i = 1;i <= mid;i++){
            for(int j = i;;j++){
                sum += j;
            if(sum < target){
                dq.push_back(j);
            }
            else if(sum > target){
                sum = 0;
                dq.clear();
                break;
            }
            else if(sum == target){
                dq.push_back(j);
                res.push_back(dq);
                dq.clear();
            }
        }
           
    }
    return res;
    }

    int main(){
        int target = 9;
        vector<vector<int>>res;
        res = findContinuousSequence(target);
        for (vector<vector<int>>::iterator it = res.begin(); it != res.end(); it++)
        {
	        for (vector<int>::iterator itit = (*it).begin(); itit != (*it).end(); itit++)
	        {
		        cout << *itit;
	        }
            cout << endl;
		}
    }