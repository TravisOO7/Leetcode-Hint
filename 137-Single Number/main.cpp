class Solution {
public:
    void positive(int num, int *arr){
        int t = 1;
        for(int i = 0; i < 32; i++){
            if( (num & t) > 0){
               
                arr[i]++;
            }
            t = t << 1;
        }
    }

    void negative(int num, int *arr){
        int t = 1;
        bool firstOne = false;
        for(int i = 0; i < 31; i++){
            if( (num & t) != 0){
                if(firstOne == false){
                    firstOne = true;
                    arr[i]++;
                }
            }else{
                if(firstOne == true){
                    arr[i]++;
                }
            }
            t = t << 1;
        }

        arr[31] += 1;
    }

    int singleNumber(vector<int>& nums) {
        int arr[32] = {0};
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0){
                positive(nums[i], arr);
            }else{
                negative(nums[i], arr);
            }
            
        }

        int num = 0;
        long long two = 1;
       for(int i = 0; i < 31; i++){
           cout<<arr[i]<<' ';
           if(arr[i] % 3 == 1){
               num += two;
           }
           two  = two << 1;
       }

        cout<<arr[31]<<endl;
        if(arr[31] % 3 != 0){

            num = num * -1;
            if(num == 0){
                num = INT_MIN;
            }
        }

        return num;

    }
};