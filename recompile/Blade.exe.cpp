
// address: 0x00401000
B_Sphere::B_Sphere()
{
    this->center.x = 0.0;
    this->center.y = 0.0;
    this->center.z = 0.0;
    this->radius = 0.0;
}

// address: 0x004015C5
B_BoundingBox::B_BoundingBox(const B_Vector &minCoords, const B_Vector &maxCoords)
{
    memcpy(this, &minCoords, 24);
    memcpy(&this->maxCoords, &maxCoords, 24);
}

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

// address: 0x00450407
int B_OctantNode::GetTypeID()
{
    return B_OCT_NODE_CID_BRANCH;
}

// address: 0x0045047C
int LeafNode::GetTypeID()
{
    return B_OCT_NODE_CID_LEAF;
}

// address: 0x004506B5
int B_SectorListNode::GetTypeID()
{
    return B_OCT_NODE_CID_SECTOR_LIST;
}

// address: 0x004507B9
B_OctTree::~B_OctTree()
{
    this->unknown_method_004507D5();
}

// address: 0x00453264
void B_OctantNodeBase::B_OctTreeSectorsList()
{
    ACCESS(this, 0, 4) = 0x00000000;
    REGDEF(eax=this)
}

// address: 0x0045346F
B_SectorSurfaceCache::B_SectorSurfaceCache()
:
    numSurfaces(0)
{
}

// address: 0x00453490
B_SectorSurfaceCache::~B_SectorSurfaceCache()
{
}

// address: 0x004539A9
B_GlobalSurfaceCache::B_GlobalSurfaceCache()
{
    this->count = 0;
    int unknown_loc_0C = 128;
    STACKVAR(-8, 4) = 0x00000110;
    STACKVAR(-4, 4) = &this->elements;
l004539D2:
    unknown_loc_0C--;
    if (unknown_loc_0C >= 0)
    {
        reinterpret_cast<B_SectorSurfaceCache *>(STACKVAR(-4, 4))->B_SectorSurfaceCache();
        STACKVAR(-4, 4) = reinterpret_cast<any_int32>(STACKVAR(-4, 4)) + reinterpret_cast<any_int32>(STACKVAR(-8, 4));
        goto l004539D2;
    }
}
