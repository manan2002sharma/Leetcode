class Solution {
public:
    int nonSpecialCount(int l, int r) {
     int nr=sqrt(r);   
     int nl=sqrt(l);
     vector<int> prime(nr+1,1);
     prime[0]=0;
     prime[1]=0;
     int count=0;
     for(int i=2;i<nr+1;i++){
        if(prime[i]==1){
            if(i*i>=l){
                
                cout<<i<<endl;
                count++;
            }
            for(int j=i*2;j<nr+1;j+=i){
                prime[j]=0;
            }
        }
     }
     
    return r-l-count+1;
    }


};