
class myc{
    public: 
    string a;
    int b;
    int c;
};
class Solution {
public:
    
    static bool cmp(string &a,string &b){
        return a.size()<b.size();
    }
    bool check(string &a,string &b){
        int x=0,y=0;
        while(x<a.size()&&y<b.size()){
            if(a[x]==b[y]) {x++;y++;}
            else y++;
        }
        return x==a.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<bool> visited(words.size(),false);
        int n=words.size();
        unordered_map<int,int> m;
        int ans=1;
        queue<myc> q;
        for(int i=0;i<n;i++){
            if(visited[i]==false)
           { myc temp;
            temp.a=words[i];
            temp.b=i;
            temp.c=1;
            visited[i]=true;
            q.push(temp);
            while(!q.empty()){
                myc x=q.front();
                q.pop();
                ans=max(ans,x.c);
                for(int j=x.b+1;j<n;j++){
                    if(words[j].size()-(x.a).size()==1&&(x.c+1)>m[j]&&check(x.a,words[j])){
                        myc neww;
                        neww.a=words[j];
                        neww.b=j;
                        neww.c=x.c+1;   
                        q.push(neww);
                        visited[j]=true;
                        m[j]=x.c+1;
                    }
                }
            }}
        }
        return ans;






        // for(int i=0;i<n;i++){
           

        //     while(){

        //     }

        //     for(int j=i+1;j<n;j++){
        //             if(words[j].size()-words[i].size()==1&&check(words[i],words[j])){
        //                 for(int k=j+1;k<n;K++){
        //                     if(words[j].size()-words[i].size()==1&&check(words[i],words[j])){

        //                     }
        //                 }
        //             }
        //     }

        // }
        // return ans;
    }
};



/*
 vector<bool> visited(words.size(),false);
            string mystring=words[i];
            int cnt=1;
                for(int j=i+1;j<n;j++){
                    if(words[j].size()-mystring.size()==1){
                        
                    }
                }
*/
/*
int x=0,y=0;
                        string a=mystring;//x
                        string b=words[j];//y
                        while(x<a.size()&&y<b.size()){
                            if(a[x]==b[y]) {x++;y++;}
                            else y++;
                        }
                        if(x==a.size()){
                            cnt++;
                            ans=max(ans,cnt);
                            mystring=words[j];
                            visited[i]=true;
                            visited[j]=true;
                        }

                        */