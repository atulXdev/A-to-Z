//https://www.naukri.com/code360/problems/check-whether-k-th-bit-is-set-or-not_5026446?leftPanelTabValue=PROBLEM

bool isKthBitSet(int n, int k)
{
   //bit is set: bit is 1 ,not set means its 0
   //by left shift
   int i=k-1;

   if((n&(1<<i))!=0){
       return true;
   }

   return false;
}

//by right shift

bool isKthBitSet(int n, int k)
{
   //bit is set: bit is 1 ,not set means its 0
   //by right shift
   int i=k-1;

   if((n>>i)&1!=0){
       return true;
   }

   return false;
}
