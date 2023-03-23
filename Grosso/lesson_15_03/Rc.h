class Rc{
    public:
        Rc();
        Rc(int);
        ~Rc(); //altGR ì
        int get_code();
        void set_code(int);

    private:
        int code = 1;
        char *arr_point;
        friend class Rc2;
        friend int get_code_extern(Rc);
};


class Rc2{
    public:
        int get_code(Rc);
};