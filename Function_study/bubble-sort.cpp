// #include<iostream>
// using namespace std;
// void bubblesort(int *arr,int len)
// {
//     int temp;
//     for(int i=0;i<len-1;i++)
//     {
//         for(int j=0;j<len-i-1;j++)
//         {
//             if(arr[j]>arr[j+1])
//             {
//                 temp =arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;

//             }
//         }
//     }
// }
// void printarray(int *arr, int len)
// {
//     for(int i=0;i<len;i++)
//     {
//          cout<<arr[i]<<endl;
//     }
// }
// int main()
// {
//     int arr[]={2,1,3,3,8,4,8,10,11};
//     int i=4;
//     i=arr[i];
//     cout<<i<<endl;
//     printarray(arr,sizeof(arr)/sizeof(arr[0]));
//     bubblesort(arr,sizeof(arr)/sizeof(arr[0]));
//     printarray(arr,sizeof(arr)/sizeof(arr[0]));
//     printf("李德康\n");
//     system("pause");
//     return 0;
// }