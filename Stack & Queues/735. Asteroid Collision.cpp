class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        //put +ve elemt in stack,anytime you encounter a -ve elemt check stack top if
        //its val is smaller pop out,or its equal poput.or after poppping all st is empty 
        //and we still have -ve elemnt then put it in stack
        for(int i=0;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
            while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                st.pop();
            }
            if(!st.empty() && st.top()==abs(asteroids[i])){
                st.pop();
            }

            //if stack empty ho jaye ,ya stack me sirf -ve bache h to same parity -ve walo ko stack me add kro
            else if(st.empty() || st.top()<0){
                st.push(asteroids[i]);
            }
            
            }



        }

          vector<int> ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        
    }
};