
// address: 0x0040A5D0
B_Vector B_Vector::operator -(const B_Vector &that) const
{
    STACKVAR(-24, 8) = this->z - that.z;
    STACKVAR(-16, 8) = this->y - that.y;
    STACKVAR(-8, 8) = this->x - that.x;
    __result->x = reinterpret_cast<double>(STACKVAR(-8, 8));
    __result->y = reinterpret_cast<double>(STACKVAR(-16, 8));
    __result->z = reinterpret_cast<double>(STACKVAR(-24, 8));
    REGDEF(eax=__result)
}
