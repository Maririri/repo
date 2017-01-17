namespace myStl
{
    class MyString
    {
    public:
        MyString(const char* str = "default");

        ~MyString(){ delete[] m_pStr;}

        MyString(const MyString & ); //классический конструктор копирования
        MyString(MyString && other); //move constructor

        MyString & operator=(const MyString & ); //классический оператор присваивания
        MyString & operator=(MyString && other); //move operator=

        friend std::ostream& operator<< ( std::ostream& os, const MyString & s);
    private:

        char* m_pStr;
    };


    //ToDo: add MyPoint obj to MyStack
    class MyPoint
    {
    public:

        MyPoint() : x(0) , y(0)
        { }

        MyPoint(int x, int y)
                : x(x)
                , y(y)
        { }

        virtual ~MyPoint() { }

        int getX() const
		{ return x; }
        void setX(int x)
		{ MyPoint::x = x; }

    private:
        int x;
        int y;
    };

    class MyFigure
    {
    public:
        enum FigureType
        {
            SQUARE,
            CIRCLE,
            UNDEFINED
        };

    private:

        FigureType type;

    };

    class MyCircle : public MyFigure
    {
    public:

        MyCircle(size_t x1, size_t y, size_t r) :  y(y), r(r) { x = x1;  }


        MyCircle()
        { }

        size_t getXY() const {
            size_t i = x+y;
            return i;	}

        friend std::ostream& operator<< ( std::ostream& os, const MyCircle& c);

        void setX(size_t x) {
            MyCircle::x = x;
        }

    private:
        size_t y;
        size_t r;
    protected:
        size_t x;
    };

    class Base
    {

        int a;
    public:
        int getA() const { return a; }
    };

    class Derivative : public Base
    {
    public:
        Derivative() {}

    };
}
