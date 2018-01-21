#include <stdio.h>
#include <math.h>
int main(){
  int i,j=0,pow_calc,temp,a,sum;
  int answer=0x328FE;
  int arr_bin[18];
  
  //0x004020FE
  int arr1[]={
    0x16,0x49,0x5E,
    0x15,0x27,0x26,
    0x21,0x25,0x1D,
    0x59,0x53,0x37,
    0x31,0x48,0x5D,
    0x0C,0x61,0x52,0x4D };
    
    //CHECK BOX -이 배열은 계산시에는 필요없음
    /* int arr2[]={
      0x61,0x49,0x5E,
      0x16,0x25,0x26,
      0x21,0x59,0x53,
      0x15,0x37,0x31,
      0x48,0x5D,0x0C,
      0x52,0x27,0x1D };
    */
    
    int ecx[]={17,2,3,1,8,6,7,10,11,4,12,13,14,15,16,18,5,9};
    int arr_result[18]={0,};
    
    printf("\n");
    
    for(i=0;i<18;i++){
      arr_result[i] = ecx[i] * arr1[ecx[i]-1] * arr1[ecx[i]-1+1 ];
      printf("ECX:%d\t",ecx[i]);
      printf("arr[%2d]:%x\t",i,arr1[i]);
      printf("arr+1[%2d]:%x\t",i,arr1[i+1]);
      printf("arr_result[%2d]:%x\n",ecx[i]-1,arr_result[i]);
    }
    printf("=============================================================\n\n");
    
    //BINARY CASE
    printf("WAIT LOADING...\n");
    //0x111111111111111111 = 0x3FFFF = 262143
    for(i=0,j=0; i<=262143; i++){ //왼쪽은 작->큰 ,우측은 큰->작
      for(i=262143,j=0;i>=0;i--){
        arr_bin[0]=i;
        //printf("arr_bin[17-j]: %d, i: %d ",arr_bin[17-j],i);
        for(j=17;j>0;j--){
          temp=arr_bin[17-j];
          pow_calc=pow(2,j); //printf("j: %d 17-j: %d temp: %d ",j,17-j,temp);    arr_bin[17-j]=temp/pow_calc;    arr_bin[17-j+1]=temp%pow_calc;    //printf("arr_bin[%d]=%d (%x)\n",17-j,arr_bin[17-j],arr_bin[17-j]);    if(17-j+1==17){     //printf("arr_bin[%d]=%d (%x)\n",17-j+1,arr_bin[17-j+1],arr_bin[17-j+1]);    }   } //printf("\n"); for(j=0,a=0,sum=0;j<18;j++){   a=arr_bin[j]*arr_result[j];   sum=sum+a;   //printf("a: %x\n",a);   //printf("sum: %x\n",sum);   }         if(sum==answer){          printf("\n************ANSWER************\n\n");          printf("DEC: %d\n",i);          printf("HEX: %x\n",i);          printf("BIN: ",i);           for(j=0;j<18;j++){                 printf("%d",arr_bin[j]);           }          printf("\n\n          CHKBOX\n",i);           for(j=0;j<18;j++){                 if(arr_bin[j]==0){printf("[ ]");}                 else{printf("[v]");}                 if(j==8){printf("\n");}           }          printf("\n\n******************************\n\n");         break;         } } return 0; }