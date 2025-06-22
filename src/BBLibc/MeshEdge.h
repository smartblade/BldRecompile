
class LIB_EXP B_MeshEdge
{
public:
    B_MeshEdge();
    B_MeshEdge(unsigned int, unsigned int, unsigned int);
    B_MeshEdge& operator=(const B_MeshEdge&);
    unsigned int operator==(const B_MeshEdge&) const;

    unsigned int field;
private:

};
