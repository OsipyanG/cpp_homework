class Figure {
   public:
    virtual int Perimeter() const = 0;
    virtual ~Figure() {}
};

class Triangle : public Figure {
   private:
    int side1, side2, side3;

   public:
    Triangle(int s1, int s2, int s3) : side1(s1), side2(s2), side3(s3) {}

    int Perimeter() const override { return side1 + side2 + side3; }
};

class Rectangle : public Figure {
   private:
    int width, height;

   public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int Perimeter() const override { return 2 * (width + height); }
};