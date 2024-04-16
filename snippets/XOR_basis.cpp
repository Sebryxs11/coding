struct XOR_basis {
    vll base;
    XOR_basis(int max_base_size) {base = vll(max_base_size, 0);}
    void inserta(ll x) {
        int Msig = (63-__builtin_clzll(x));
        while (Msig + 1) {
            if (!base[Msig]) base[Msig] = x;
            x = (x ^ base[Msig]);
            Msig = (63-__builtin_clzll(x));
        }
    }
    bool query(ll x) {
        int Msig = (63-__builtin_clzll(x));
        while (Msig + 1) {
            if (!base[Msig]) return false;
            x = (x ^ base[Msig]);
            Msig = (63-__builtin_clzll(x));
        }
        return true;
    }
};
