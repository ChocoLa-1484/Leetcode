class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for (auto t : patterns) {
            vector<int> F = build(t);
            ans += match(word, t, F);
        }
        return ans;
    }
    vector<int> build(string& t) {
        vector<int> F(t.size());
        F[0] = -1;
        for (int i = 1, pos = -1; i < t.size(); i++) {
            while (~pos && t[i] != t[pos + 1])
                pos = F[pos];
            if (t[i] == t[pos + 1])
                pos++;
            F[i] = pos;
        }
        return F;
    }
    bool match(string& s, string& t, vector<int>& f) {
        for (int i = 0, pos = -1; i < s.size(); i++) {
            while (~pos && s[i] != t[pos + 1])
                pos = f[pos];
            if (s[i] == t[pos + 1])
                pos++;
            if (pos + 1 == (int)t.size()) {
                return 1;
                pos = f[pos];
            }
        }
        return 0;
    }
};

class Solution {
    static constexpr int N = 10005;
    class ACAutomaton {
    public: 
        struct Node {
            int son[26];
            int fail;
            vector<int> out;
            void init() {
                memset(son, 0, sizeof(son));
                fail = 0;
                out.clear();
            }
        } tr[N];
        int tot;
        void init() { 
            tot = 0; 
            tr[0].init();
        }
        void insert(const string &s, int id) {
            int u = 0;
            for (char ch : s) {
                int &son = tr[u].son[ch - 'a'];
                if (!son) {
                    son = ++tot;
                    tr[son].init();
                }
                u = son;
            }
            tr[u].out.push_back(id);
        }
        void build() {
            queue<int> q;
            for (int c = 0; c < 26; c++) {
                if (tr[0].son[c]) {
                    q.push(tr[0].son[c]);
                }
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int c = 0; c < 26; c++) {
                    int v = tr[u].son[c];
                    if (v) {
                        tr[v].fail = tr[tr[u].fail].son[c];
                        for (int id : tr[tr[v].fail].out)
                            tr[v].out.push_back(id);
                        q.push(v);
                    } else {
                        tr[u].son[c] = tr[tr[u].fail].son[c];
                    }
                }
            }
        }
        int query(const string &text, int n) {
            vector<bool> vis(n, false);
            int ans = 0;
            int u = 0;
            for (char ch : text) {
                u = tr[u].son[ch - 'a'];
                for (int id : tr[u].out) {
                    if (!vis[id]) {
                        vis[id] = true;
                        ans++;
                    }
                }
            }
            return ans;
        }
    };
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        ACAutomaton AC;
        AC.init();
        for (int i = 0; i < n; i++) {
            AC.insert(patterns[i], i);
        }
        AC.build();
        return AC.query(word, n);
    }
};