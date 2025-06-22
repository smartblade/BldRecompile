
class LIB_EXP B_RDataLight
{
public:
    B_RDataLight();
    B_RDataLight(float, float, float, float);

    void Interp(double, B_RDataLight&, double, B_RDataLight&);

    B_RDataLight& operator=(const B_RDataLight&);

private:

};
