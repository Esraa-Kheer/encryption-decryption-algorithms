#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;
///////////////////////PLAY FAIR//////////////////////////////////////////////////////////////////////////////////////////////////////////
void encrypt()
{
    const int N=100;
         char letters[26]="ABCDEFGHIKLMNOPQRSTUVWXYZ";//Used to fill the matrix
         int flag[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 ,0,0,0};//Whether the letter is already in the matrix, corresponding to the letters array
         char ch[5][5];//5X5 matrix
         char ch1[N];//Key
         char ch2[N];//plain text
         char ch4;//irrelevant characters
    int len='a'-'A';
         cout<<"Enter key:";
    cin>>ch1;
    int flg=1;
    while(flg==1)
    {
                 for(int i=0;i<strlen(ch1);i++)//Convert the entered key into uppercase letters
        {
            if(ch1[i]>'z'||ch1[i]<'a')
            {
                                 cout<<"Please re-select the operation:"<<endl;
                flg=0;break;
            }
            else
                ch1[i]=ch1[i]-len;
        }
        if(flg==1)
                 {for(int i=0;i<strlen(ch1);i++)//change all J in the key to I
        {
            if(ch1[i]=='J')ch1[i]='I';
        }
        int i=0;int j=0;
 //Fill the letter in the key into the matrix and mark the letter as used
        for(int k=0;k<strlen(ch1);k++)
        {
            for(int t=0;t<25;t++)
            {
                if(ch1[k]==letters[t]&&flag[t]==0)
                {
                    ch[i][j]=letters[t];
                    flag[t]=1;
                    if(j<4)j++;
                    else {i++;j=0;}
                }
            }
        }
                 for( int k=0;k<25;k++)//Fill the unused letters into the matrix in alphabetical order
        {
            if(flag[k]==0)
            {
                ch[i][j]=letters[k];
                flag[k]=1;
                if(j<4)j++;
                else{i++;j=0;}
            }
        }
                 cout<<"The matrix after the key is filled is: "<<endl;
        for(i=0;i<5;i++)
          for(j=0;j<5;j++)
            {
                cout<<ch[i][j];
                cout<<" ";
                if(j==4)
                    cout<<endl;
            }
            cout<<endl;
                         cout<<"Please enter plain text (please enter English characters):";
            cin>>ch2;
                         cout<<"Enter an irrelevant character:";
            cin>>ch4;
            if(ch4>='a')
                ch4=ch4-len;
                         for(int k=0;k<strlen(ch2);k++)//Convert the entered plaintext into uppercase letters
            {
                if(ch2[k]>='a')
                    ch2[k]=ch2[k]-len;
            }
                         for(int k=0;k<strlen(ch2);k++)//change all J in the plaintext to I
            {
                if(ch2[k]=='J')
                    ch2[k]='I';
            }
 //Add necessary irrelevant characters to the plaintext to prevent two characters in the same group from being the same
            for( int k=0;k<strlen(ch2);k+=2)
            {
                if(ch2[k]==ch2[k+1])
                {
                    for(int t=strlen(ch2);t>k;t--)
                        ch2[t+1]=ch2[t];
                    ch2[k+1]=ch4;
                }
            }
 //If the plaintext has an odd number of characters, add an extraneous character to make up an even number
            if(strlen(ch2)%2!=0)
            {
                                 ch2[strlen(ch2)+1]=ch2[strlen(ch2)];//Assign'\0' to the end of the string
                                 ch2[strlen(ch2)]=ch4;//Insert irrelevant characters at the end of the plaintext string
            }
                         cout<<"The plaintext after processing is:";
            for(int k=0;k<strlen(ch2);k+=2)
                cout<<ch2[k]<<ch2[k+1]<<" ";
            cout<<endl;
                         cout<<"The final length is: "<<strlen(ch2)<<endl;
                         ////////////////// Clear text input and finishing /////////////////////////// ////
            for(int k=0;k<strlen(ch2);k+=2)
            {
                int m1,m2,n1,n2;
                for(m1=0;m1<=4;m1++)
                {for(n1=0;n1<=4;n1++)
                {
                    if(ch2[k]==ch[m1][n1])break;
                }
                if(ch2[k]==ch[m1][n1])break;
                }
                for(m2=0;m2<=4;m2++)
                {
                    for(n2=0;n2<=4;n2++)
                    {
                        if(ch2[k+1]==ch[m2][n2])break;
                    }
                    if(ch2[k+1]==ch[m2][n2])break;
                }
                m1=m1%5;
                m2=m2%5;
                if(n1>4){n1=n1%5;m1=m1+1;}
                if(n2>4){n2=n2%5;m2=m2+1;}
                if(m1==m2)
                {
                    ch2[k]=ch[m1][(n1+1)%5];
                    ch2[k+1]=ch[m2][(n2+1)%5];
                }
                else
                {
                    if(n1==n2)
                    {
                        ch2[k]=ch[(m1+1)%5][n1];
                        ch2[k+1]=ch[(m2+1)%5][n2];
                    }
                    else
                    {ch2[k]=ch[m1][n2];
                    ch2[k+1]=ch[m2][n1];
                    }
                }
            }
                         cout<<"The ciphertext obtained after encryption is:";
            for(int k=0;k<strlen(ch2);k+=2)
                cout<<ch2[k]<<ch2[k+1]<<" ";
            cout<<endl;
        }else break;
        }

}

 //Decryption algorithm
void decrypt()
{
    const int N=100;
         char letters[26]="ABCDEFGHIKLMNOPQRSTUVWXYZ";//Used to fill the matrix
    int flag[25]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
         //Mark whether the letter is already in the matrix, corresponding to the letters array
         char ch[5][5];//5X5 matrix
         char ch1[N];//Key
         char ch2[N];//ciphertext
    int len='a'-'A';
    int flg=1;
         cout<<"Enter key:";
    cin>>ch1;
    while(flg==1)
    {
                 for(int i=0;i<strlen(ch1);i++)//Convert the entered key into uppercase letters
        {if(ch1[i]>'z'||ch1[i]<'a')
        {
                         cout<<"Please re-select the operation:"<<endl;
            flg=0;break;
        }
        else
            ch1[i]=ch1[i]-len;
        }
        if(flg==1)
                 {for(int i=0;i<strlen(ch1);i++)//change all J in the key to I
{
            if(ch1[i]=='J')ch1[i]='I';
        }
        int i=0;int j=0;
                 //Fill the letter in the key into the matrix and mark the letter as used
for(int k=0;k<strlen(ch1);k++)
        {
            for( int t=0;t<25;t++)
            {
                if(ch1[k]==letters[t]&&flag[t]==0)
                {
                    ch[i][j]=letters[t];
                    flag[t]=1;
                    if(j<4)j++;
                    else {i++;j=0;}
                }
            }
        }
                 for( int k=0;k<25;k++)//Fill the unused letters into the matrix in alphabetical order
        {
            if(flag[k]==0)
            {
                ch[i][j]=letters[k];
                flag[k]=1;
                if(j<4)j++;
                else{i++;j=0;}
            }
        }
                 cout<<"The matrix after the key is filled is: "<<endl;
        for(i=0;i<5;i++)

            for(j=0;j<5;j++)
            {
                cout<<ch[i][j];
                cout<<" ";
                if(j==4)
                    cout<<endl;
            }
            cout<<endl;
                         /////////////////////Matrix generation completed////////////////////////// //
            int f=0;
            do{
                                 cout<<"Please enter ciphertext (English characters):";
                cin>>ch2;
                                 for(int k=0;k<strlen(ch2);k++)//Convert the entered ciphertext into uppercase letters
                {
                    if(ch2[k]>='a')
                        ch2[k]=ch2[k]-len;
                }
                                 for( int k=0;k<strlen(ch2);k++)//change all J in the ciphertext to I
                {
                    if(ch2[k]=='J')ch2[k]='I';
                }
                for( int k=0;k<strlen(ch2);k+=2)
                {
                    if(ch2[k]==ch2[k+1])
                    {
                                                 cout<<"The same characters cannot appear in the same group! Please re-enter."<<endl;
                        f=1;
                        break;
                    }else f=2;
                }
                if(f==1)continue;
                if(strlen(ch2)%2!=0)
                {
                    cout<<"The string cannot be an odd number! Please re-enter."<<endl;
                    f=1;
                }
                else f=2;
            }while(f==1);
                         //Decryption begins
            for( int k=0;k<strlen(ch2);k+=2)
            {
                int m1,m2,n1,n2;
                for(m1=0;m1<=4;m1++)
                {
                    for(n1=0;n1<=4;n1++)
                    {
                        if(ch2[k]==ch[m1][n1])break;
                    }
                    if(ch2[k]==ch[m1][n1])break;
                }
                for(m2=0;m2<=4;m2++)
                {
                    for(n2=0;n2<=4;n2++)
                    {
                        if(ch2[k+1]==ch[m2][n2])break;
                    }
                    if(ch2[k+1]==ch[m2][n2])break;
                }
                m1=m1%5;
                m2=m2%5;
                if(n1>4){n1=n1%5;m1=m1+1;}
                if(n2>4){n2=n2%5;m2=m2+1;}
                if(m1==m2)
                {ch2[k]=ch[m1][(n1+4)%5];
                ch2[k+1]=ch[m2][(n2+4)%5];
                }
                else
                {
                    if(n1==n2)
                    {
                        ch2[k]=ch[(m1+4)%5][n1];
                        ch2[k+1]=ch[(m2+4)%5][n2];
                    }
                    else
                    {
                        ch2[k]=ch[m1][n2];
                        ch2[k+1]=ch[m2][n1];
                    }
                }
            }
                         cout<<"The plaintext obtained after decryption is:";
            for(int k=0;k<strlen(ch2);k+=2)
                cout<<ch2[k]<<ch2[k+1]<<" ";
            cout<<endl;
      }
      else break;
        }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int choice;
    cout<<"WHICH ALGORITHM DO YOU WANT TO USE\n";
    cout<<"--------------------------------------------------------------------------\n";
    cout<<"1- CEASAR \n";
    cout<<"2- PLAYFAIR\n";
    cout<<"3- POLYALPHABETIC(VIGENERE)\n";
    cout<<"4- RAIL FENCE\n";
    cin>>choice;
    switch (choice){
case 1:
    {
    int i,j,k;
    string s,t;
    int key;
    int oper;
    cout<<"Which process do you want?\n";
    cout<<"1- ENCRYPT.\n";
    cout<<"2- DECRYPT.\n";
    cout<<"-----------------CHOOSE 1 OR 2-----------------\n";
    cin>>oper;
    switch (oper){
    case 1:{
        cout<<"Enter the key\n";
        cin>>key;
        cout<<"Enter the message\n";
        cin>>s;
        for(i=0;i<s.size();i++){
            t+=(s[i]-'a'+key)%26+'a';
        }
        cout<<"\n\nEncrypted message is "<<t<<'\n';
        return 0;
        break;
    }
    case 2:
        cout<<"Enter the key\n";
        cin>>key;
        cout<<"Enter the message to decrypt\n";
        cin>>s;
        for(i=0;i<s.size();i++){
            t+=(s[i]-'a'-key+26)%26+'a';
        }
        cout<<"\n\nDecrypted message is "<<t<<'\n';
        return 0;
        break;
    default :
        cout << "Error! The input is not correct";
    break;
    }
    }


case 2:{
    int oper;
    cout<<"Which process do you want?\n";
    cout<<"1- ENCRYPT.\n";
    cout<<"2- DECRYPT.\n";
    cout<<"-----------------CHOOSE 1 OR 2-----------------\n";
    while(true)
    {
        cin>>oper;
        switch(oper)
        {
        case 1:{
            encrypt();
            break;
        }
        case 2:{
            decrypt();
            break;
        }
            default:
                cout << "Error! The input is not correct";
        }
    }
    break;
    }


case 3:
    {
    int i,j,k,n;
    string s;
    string key;
    vector<vector<char> > a(26,vector<char>(26));
    k=0;
    n=26;
    for(i=0;i<n;i++){
        k=i;
        for(j=0;j<n;j++){
            a[i][j]='a'+k;
            k++;
            if(k==26)
                k=0;
        }
    }
    int oper;
    cout<<"Which process do you want?\n";
    cout<<"1- ENCRYPT.\n";
    cout<<"2- DECRYPT.\n";
    cout<<"-----------------CHOOSE 1 OR 2-----------------\n";
    cin>>oper;
    switch (oper){
    case 1:{
    cout<<"Enter the message\n";
    cin>>s;
    cout<<"Enter the key\n";
    cin>>key;
    k=0;
    int mod = key.size();
    for(i=key.size();i<s.size();i++){
        key+=key[k%mod];
        k++;
    }
    string encrypt;
    for(i=0;i<s.size();i++){
        encrypt+= a[s[i]-'a'][key[i]-'a'];
    }
    cout<<"Encrypted message: "<<encrypt<<'\n';
    return 0;
    break;
    }
    case 2 :{
    cout<<"Enter the encrypted message\n";
    cin>>s;
    cout<<"Enter the key\n";
    cin>>key;
    k=0;
    for(i=key.size();i<s.size();i++){
        key+=key[k];
        k++;
    }
    string decrypt;
    for(i=0;i<s.size();i++){
        for(j=0;j<n;j++){
            if(a[j][key[i]-'a']==s[i]){
                decrypt += 'a'+j;
            }
        }
    }
    cout<<"Decrypted message: "<<decrypt<<'\n';
    return 0;
    break;
    }
    default:
        cout << "Error! The input is not correct";
    }
    break;
    }
case 4:{
    cout<<"Which process do you want?\n";
    cout<<"1- ENCRYPT.\n";
    cout<<"2- DECRYPT.\n";
    cout<<"-----------------CHOOSE 1 OR 2-----------------\n";
    string text;
    int ober,key;
    cin>>ober;
    switch (ober){
    case 1:{
        int t,n,m,i,j,k,sum=0;
    string s;
    cout<<"Enter the message"<<'\n';
    cin>>s;
    cout<<"Enter key"<<'\n';
    cin>>n;
    vector<vector<char> > a(n,vector<char>(s.size(),' '));
    j=0;
    int flag=0;
    for(i=0;i<s.size();i++){
        a[j][i] = s[i];
         if(j==n-1){
            flag=1;
        }
        else if(j==0)
            flag=0;
        if(flag==0){
            j++;
        }
        else j--;
    }
    for(i=0;i<n;i++){
        for(j=0;j<s.size();j++){
            if(a[i][j]!=' ')
                cout<<a[i][j];
        }
    }
    cout<<'\n';

        break;
    }
    case 2:{
        int t,n,m,i,j,k,sum=0;
    string s;
    cout<<"Enter the message to decrypt"<<'\n';
    cin>>s;
    cout<<"Enter key"<<'\n';
    cin>>n;
    vector<vector<char> > a(n,vector<char>(s.size(),' '));
    j=0;
    int flag=0;
    for(i=0;i<s.size();i++){
        a[j][i] = '0';
         if(j==n-1){
            flag=1;
        }
        else if(j==0)
            flag=0;
        if(flag==0){
            j++;
        }
        else j--;
    }
    int temp =0;
    for(i=0;i<n;i++){
        for(j=0;j<s.size();j++){
                if(a[i][j]=='0')
                    a[i][j]= s[temp++];
        }
    }
    flag=0;
    j=0;
    for(i=0;i<s.size();i++){
        cout<<a[j][i];
         if(j==n-1){
            flag=1;
        }
        else if(j==0)
            flag=0;
        if(flag==0){
            j++;
        }
        else j--;
    }
    cout<<'\n';
    return 0;

        break;
    }
    default:
        cout<<"INCORRECT CHOICE";
    }
    break;
    }
default:
    cout<<"INCORRECT CHOICE";
    }
    return 0;
}

