struct DSU {
    vector <int> dsu_father,dsu_size;
    DSU(int max_dsu_size) {
        dsu_father = vector <int> (max_dsu_size+1,0);
        dsu_size = vector <int> (max_dsu_size+1,0);
    }
    int father(int node) {
        if (!dsu_size[node]) {
            dsu_size[node] = 1;
            dsu_father[node] = node;
        }
        if (dsu_father[node] == node) return node;
        return dsu_father[node] = father(dsu_father[node]);
    }
    void link(int node_a, int node_b) {
        node_a = father(node_a);
        node_b = father(node_b);
        if (node_a == node_b) return;
        if (dsu_size[node_a] < dsu_size[node_b]) swap(node_a,node_b);
        dsu_size[node_a] += dsu_size[node_b];
        dsu_father[node_b] = node_a;
        return;
    }
};
