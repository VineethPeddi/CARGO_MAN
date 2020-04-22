#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

class Container
{
    public:
    int length;
    int weight;
    int destination;
    int id;
};

bool sortByLength(Container &a,Container &b)
{
    return a.length > b.length;
}
int main()
{
    int lenShip;
    int widShip;
    int capShip;
    int levShip;
    int noDes;
    cout<<"\nEnter the length and width of ship(in feet): ";
    cin>>lenShip>>widShip;
    cout<<"\nEnter the capacity of ship(in tonnes) : ";
    cin>>capShip;
    cout<<"\nEnter the maximum levels in the ship: ";
    cin>>levShip;
    cout<<"\nEnter the number of destinations :";
    cin>>noDes;

    Container con[100];
    int x=0;
    int var = capShip;
    while(var)
    {
        cout<<"\n"<<var<<" tonnes of weight is still remaining...\n";
        cout<<"\nLength of container"<<x+1<<": ";
        int a;
        cin>>a;
        con[x].length = a;
        cout<<"\nWeight of container"<<x+1<<": ";
        cin>>a;
        con[x].weight = a;
        cout<<"\nDestination of container"<<x+1<<": ";
        cin>>a;
        con[x].destination = a;
        var -= con[x].weight;
        con[x].id = x+1;
        x++;
    }
    
    cout<<endl;
    cout<<endl;
    cout<<"ID\tLen\tWeight\tDestination"<<endl;
    for(int i=0;i<x;i++) {
        cout<<con[i].id<<"\t"<<con[i].length<<"\t"<<con[i].weight<<"\t"<<con[i].destination<<endl;
    }
    cout<<endl;
    cout<<endl;
    vector<Container> destContainer[noDes+1];
    for(int i=0;i<x;i++) {
        destContainer[con[i].destination].push_back(con[i]);
    }

    int noRows = widShip/8;
    int noCols = lenShip/10;

    Container ship[levShip][noRows][noCols];
    for(int i=0;i<levShip;i++) {
        for(int j=0;j<noRows;j++) {
            for(int k=0;k<noCols;k++) {
                ship[i][j][k].id = 0;
                ship[i][j][k].weight = 0;
            }
        }
    }

    int weight1=0,weight2=0;

    if(noRows%2 == 0) {
        int mid = noRows/2;
        int row1 = mid-1,col1 = 0;
        int row2 = mid,col2 = 0;
        int height1 = levShip-1;
        int height2 = levShip-1;
        for(int i = noDes;i>=1;i--) {
            vector<Container> vec = destContainer[i];
            sort(vec.begin(),vec.end(),sortByLength);
            int cnt=0;
            for(auto ele: vec) {
                //cout<<"ID - "<<ele.id<<" "<<"cnt -"<<cnt<<endl;
                cnt++;
               // cout<<"weight1 is "<<weight1<<"\t weight2 is "<<weight2<<endl;
                if(weight1 <= weight2) {
                       // cout<<"w1 less than w2"<<endl;
                    if(col1 + ele.length/10 <= noCols) {
                        for(int j=0;(j<ele.length/10);j++) {
                            
                                //cout<<"height ="<<height1<<","<<"row="<<row1<<","<<"col="<<col1+j<<endl;
                                ship[height1][row1][col1+j] = ele;
                            
                        }  
                        col1 += ele.length/10;
                        weight1 += ele.weight;
                    }
                    else {
                        row1--;
                        if(row1 == -1 ) {
                            row1 = mid-1;
                            height1--;
                        }
                        col1 = 0;
                        for(int j=0;(j<ele.length/10);j++) {
                            
                               // cout<<"height ="<<height1<<","<<"row="<<row1<<","<<"col="<<col1+j<<endl;
                                ship[height1][row1][col1+j] = ele;
                            
                        }  
                        col1 += ele.length/10;
                        weight1 += ele.weight;
                    }   
                }
                else {
                   // cout<<"w2 less than w1"<<endl;
                    if(col2 + ele.length/10 <= noCols) {
                        for(int j=0;j<ele.length/10;j++) {
                            
                            ship[height2][row2][col2+j] = ele;
                           // cout<<"height ="<<height2<<","<<"row="<<row2<<","<<"col="<<col2+j<<endl;
                            
                        }
                        col2 += ele.length/10;
                        weight2 += ele.weight;
                    }
                    else {
                        row2++;
                        if(row2 == noRows) {
                            height2--;
                            row2 = mid;
                        }
                        col2 = 0;
                        for(int j=0;j<ele.length/10;j++) {
                            
                            ship[height2][row2][col2+j] = ele;
                           // cout<<"height ="<<height2<<","<<"row="<<row2<<","<<"col="<<col2+j<<endl;
                            
                        }
                        col2 += ele.length/10;
                        weight2 += ele.weight;
                    }
                }
            }        
        }
    }
    else {
        int mid = noRows/2;
        int row1 = mid,col1 = 0;
        int row2 = mid+1,col2 = 0;
        int height1 = levShip-1;
        int height2 = levShip-1;
        for(int i = noDes;i>=1;i--) {
            vector<Container> vec = destContainer[i];
            sort(vec.begin(),vec.end(),sortByLength);
            int cnt=0;
            for(auto ele: vec) {
               // cout<<"ID - "<<ele.id<<" "<<"cnt -"<<cnt<<endl;
                cnt++;
               // cout<<"weight1 is "<<weight1<<"\t weight2 is "<<weight2<<endl;
                if(weight1 <= weight2) {
                       // cout<<"w1 less than w2"<<endl;
                    if(col1 + ele.length/10 <= noCols) {
                        for(int j=0;(j<ele.length/10);j++) {
                            
                              //  cout<<"height ="<<height1<<","<<"row="<<row1<<","<<"col="<<col1+j<<endl;
                                ship[height1][row1][col1+j] = ele;
                            
                        }  
                        col1 += ele.length/10;
                        weight1 += ele.weight;
                    }
                    else {
                        row1--;
                        if(row1 == -1 ) {
                            row1 = mid-1;
                            height1--;
                        }
                        col1 = 0;
                        for(int j=0;(j<ele.length/10);j++) {
                            
                               // cout<<"height ="<<height1<<","<<"row="<<row1<<","<<"col="<<col1+j<<endl;
                                ship[height1][row1][col1+j] = ele;
                            
                        }  
                        col1 += ele.length/10;
                        weight1 += ele.weight;
                    }   
                }
                else {
                   // cout<<"w2 less than w1"<<endl;
                    if(col2 + ele.length/10 <= noCols) {
                        for(int j=0;j<ele.length/10;j++) {
                            
                            ship[height2][row2][col2+j] = ele;
                          //  cout<<"height ="<<height2<<","<<"row="<<row2<<","<<"col="<<col2+j<<endl;
                            
                        }
                        col2 += ele.length/10;
                        weight2 += ele.weight;
                    }
                    else {
                        row2++;
                        if(row2 == noRows) {
                            height2--;
                            row2 = mid;
                        }
                        col2 = 0;
                        for(int j=0;j<ele.length/10;j++) {
                            
                            ship[height2][row2][col2+j] = ele;
                          //  cout<<"height ="<<height2<<","<<"row="<<row2<<","<<"col="<<col2+j<<endl;
                            
                        }
                        col2 += ele.length/10;
                        weight2 += ele.weight;
                    }
                }
            }        
        }
    }

    for(int h = levShip-1;h>=0;h--) {
        cout<<"Level -"<<h<<endl;
        for(int r = 0;r<noRows;r++) {
            for(int c = 0;c < noCols;c++) {
                cout<<setw(3)<<ship[h][r][c].id<<" ";
            }
            cout<<endl;
        }
        cout<<"========================================="<<endl;
    }
    
    cout<<"weight of the first half :"<<weight1<<endl;
    cout<<"weight on the second half :"<<weight2<<endl;
   /* for(int i=0;i<x;i++) {
        cout<<"\nContainer-"<<i<<endl;
        cout<<"Length: "<<con[i].length<<endl;
        cout<<"Weight: "<<con[i].weight<<endl;
        cout<<"Destination: "<<con[i].destination<<endl;
    } */
    int queries;
    cout<<"\nEnter no of queries for weight:"<<endl;
    cin>>queries;
    while(queries--)
    {
        int x1,y1;
        cout<<"Enter any point"<<endl;
        cin>>x1>>y1;
        int weightSum = 0;
        for(int i=0;i<levShip;i++) {
            weightSum += ship[i][x1][y1].weight;
        }
        cout<<"The weight at point "<<x1<<","<<y1<<" is = "<<weightSum<<endl;
    }
    return 0;
}