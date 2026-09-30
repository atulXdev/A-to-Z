class Solution {
public:
    int trap(vector<int>& height) {
// common sense:To water get trapped between the building, smaller building left and right then and only water will be trapped.
// water will be stored till the minimum hieght of the two bigger building.
// Ans will be direct: summation of min(leftmaxheight,rightmaxheight)-arr[i].Both leftmaxheight and rightmaxheight > arr[i] then only it can store water

        int n=height.size();
        //making a prefix max array for a partciular index it will have maximum val encountred till now
        vector<int> prefixmax(n,0);
        int maxi=height[0];
        prefixmax[0]=maxi;
        for(int i=1;i<height.size();i++){
            maxi=max(maxi,height[i]);
            prefixmax[i]=maxi;
            }

    //making a suffixmax array which will have max elemnet at a partcular index encontred till right
    vector<int> suffixmax(n,0);
    maxi=height[n-1];
    suffixmax[0]=maxi;
    for(int i=n-2;i>=0;i--){
        maxi=max(maxi,height[i]);
        suffixmax[i]=maxi;
    }

    //now the main logic
    int total=0;
    for(int i=0;i<n;i++){
        int leftmax=prefixmax[i];
        int rightmax=suffixmax[i];

        if(height[i]<leftmax && height[i]<rightmax){
            total+=min(leftmax,rightmax)-height[i];
        }

    }

    return total;

        
    }
};