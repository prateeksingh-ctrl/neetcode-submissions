class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>stack1;
        for(const string& op :operations){
            if(op =="+"){
                int top= stack1.back();stack1.pop_back();
                int newTop=top+stack1.back();
                stack1.push_back(top);
                stack1.push_back(newTop);

            }
            else if(op=="D"){
                stack1.push_back(2* stack1.back());

            }
            else if (op=="C"){
                stack1.pop_back();

            }
            else{
                stack1.push_back(stoi(op));
            }
        }
        return accumulate(stack1.begin(),stack1.end(),0);
        
    }
};