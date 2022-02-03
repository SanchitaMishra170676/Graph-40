class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wordList) {
        set<string> w;
        for(auto it: wordList){
            w.insert(it);
        }
        
        map<string,bool> v;
        queue<pair<string,int>> q;
        v[bw]=1;
        q.push({bw,0});
        while(! q.empty()){
            auto val = q.front();
            q.pop();
             cout<<val.first<<" ";
                if(val.first==ew){
                    return val.second+1;
                }
            for(int i=0;i<val.first.length();i++){
                string temp = val.first;
               
                
                for(int j=0;j<26;j++){
                    char ch= 'a'+j;
                    string st(1,ch);
                    temp.replace(i,1,st);
                    if(w.find(temp)==w.end()){
                        continue;
                    }
                    if(!v[temp]){
                        q.push({temp,val.second+1});
                        v[temp]=1;
                    }
                }
                
                
                
            }
            
            
        }
        
        return 0;
        
        
        
        
    }
};