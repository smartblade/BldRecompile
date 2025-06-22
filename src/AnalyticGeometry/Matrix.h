class B_Vector;

class B_Matrix
{
public:
    B_Matrix();
    B_Matrix(const B_Vector &v);
    B_Vector TranslationVector() const;
private:
    double m[4][4];
};
