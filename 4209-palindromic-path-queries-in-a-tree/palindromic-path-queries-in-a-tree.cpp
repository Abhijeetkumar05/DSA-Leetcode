
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n), tin(n), tout(n);
        int timer = 0;

        vector<tuple<int, int, int>> st;
        st.push_back({0, 0, 0});

        while (!st.empty()) {
            auto [u, p, state] = st.back();
            st.pop_back();

            if (state == 0) {
                tin[u] = timer++;
                up[0][u] = p;

                for (int j = 1; j < LOG; j++)
                    up[j][u] = up[j - 1][up[j - 1][u]];

                st.push_back({u, p, 1});

                for (int v : adj[u]) {
                    if (v == p) continue;
                    depth[v] = depth[u] + 1;
                    st.push_back({v, u, 0});
                }
            } else {
                tout[u] = timer - 1;
            }
        }

        vector<int> bit(n + 2, 0);

        auto add = [&](int idx, int mask) {
            for (int i = idx; i < (int)bit.size(); i += i & -i)
                bit[i] ^= mask;
        };

        auto rangeXor = [&](int l, int r, int mask) {
            add(l + 1, mask);
            add(r + 2, mask);
        };

        auto pointQuery = [&](int idx) {
            int result = 0;
            for (int i = idx + 1; i > 0; i -= i & -i)
                result ^= bit[i];
            return result;
        };

        auto charMask = [&](char c) {
            return 1 << (c - 'a');
        };

        for (int u = 0; u < n; u++)
            rangeXor(tin[u], tout[u], charMask(s[u]));

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return up[0][u];
        };

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            int u;
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                if (s[u] != c) {
                    int delta = charMask(s[u]) ^ charMask(c);
                    rangeXor(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int mask = pointQuery(tin[u]) ^
                           pointQuery(tin[v]) ^
                           charMask(s[w]);

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};
