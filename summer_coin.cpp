#include<iostream>
#include<vector>

using namespace std;

int a[2][10005]={0};
vector<vector<int>> table;
int cmax,cmin;

int main (){
    int d,num;
    cin >> d;
    for(int i=0 ;i<2 ;i++){
        for(int j=0 ; j<d ; j++){
            cin >> num;
            a[i][j]=num;
            //table.assign(num,j);
        }
    }//cout<<a[1][2]<<'\n';
    int origin=a[0][0],mem=-1;
    for(int i=0;i<d;i++){
        origin+=a[1][i];
        //cout<<"origin="<<origin<<endl;
    }
    cmin=origin;
    for(int i=0;i<d-1;i++){
        origin=origin-a[1][i]+a[0][i+1];
        //cout<<"origin="<<origin<<endl;
        if(origin<=cmin)cmin=origin,mem=i;
    }
    cout<<"i="<<mem<<endl;
    if(d==0)cmax=0;
    else if(mem==d-1){
        for(int i=0;i<d-1;i++)cmax+=a[1][i];
    }else if(mem==-1){
        for(int i=1;i<d;i++)cmax+=a[0][i];
    }else{
        int up=0,down=0;
        for(int i=0;i<=mem;i++)down+=a[1][i];
        for(int i=mem+2;i<d;i++)up+=a[0][i];//沒算到的
        //cout<<"up="<<up<<" ,down="<<down<<endl;
        cmax=up>down?up:down;
    }
    cout<<cmax<<endl;
}