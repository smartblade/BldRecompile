
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

// address: 0x00450327
B_OctantNode::B_OctantNode()
{
    ACCESS(this, 0, 4) = GLOBAL(0x005BDD0C);
    gbl_node_count++;
    ACCESS(this, 0, 4) = GLOBAL(0x005BDCFC);
    unsigned int unknown_loc_04 = 0;
    goto l00450363;
l0045035A:
    unknown_loc_04++;
l00450363:
    if (unknown_loc_04 < 8)
    {
        ACCESS(ARRPTR(this, 4, unknown_loc_04, 4), 0, 4) = 0x00000000;
        goto l0045035A;
    }
}

// address: 0x00450380
B_OctantNode::~B_OctantNode()
{
    unsigned int unknown_loc_04 = 0;
    goto l004503A4;
l0045039B:
    unknown_loc_04++;
l004503A4:
    if (unknown_loc_04 < 8)
    {
        if (ACCESS(ARRPTR(this, 4, unknown_loc_04, 4), 0, 4) != 0x00000000)
        {
            STACKVAR(-12, 4) = ACCESS(ARRPTR(this, 4, unknown_loc_04, 4), 0, 4);
            STACKVAR(-8, 4) = STACKVAR(-12, 4);
            if (STACKVAR(-8, 4) != 0x00000000)
            {
                STACKVAR(-20, 4) = STACKVAR(-8, 4)->(ACCESS(ACCESS(STACKVAR(-8, 4), 0, 4), 4, 4))(0x00000001);
            }
            else
            {
                STACKVAR(-20, 4) = 0x00000000;
            }
        }
        goto l0045039B;
    }
    ACCESS(this, 0, 4) = GLOBAL(0x005BDD0C);
    gbl_node_count--;
}

// address: 0x00450407
int B_OctantNode::GetTypeID()
{
    return B_OCT_NODE_CID_BRANCH;
}

// address: 0x00450417
LeafNode::LeafNode()
{
    ACCESS(this, 0, 4) = GLOBAL(0x005BDD0C);
    gbl_node_count++;
    this->sectors = nullptr;
    ACCESS(this, 0, 4) = GLOBAL(0x005BDD1C);
}

// address: 0x00450450
LeafNode::~LeafNode()
{
    ACCESS(this, 0, 4) = GLOBAL(0x005BDD0C);
    gbl_node_count--;
}

// address: 0x0045047C
int LeafNode::GetTypeID()
{
    return B_OCT_NODE_CID_LEAF;
}

// address: 0x0045048C
B_SectorListNode::B_SectorListNode()
{
    ACCESS(this, 0, 4) = GLOBAL(0x005BDD0C);
    gbl_node_count++;
    STACKVAR(-4, 4) = reinterpret_cast<any_int32>(this) + 0x00000004;
    ACCESS(STACKVAR(-4, 4), 4, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 12, 4) = 0x00000001;
    ACCESS(STACKVAR(-4, 4), 16, 4) = 0x00000000;
    ACCESS(STACKVAR(-4, 4), 20, 4) = 0x00000001;
    ACCESS(STACKVAR(-4, 4), 0, 4) = GLOBAL(0x005BDB7C);
    ACCESS(this, 0, 4) = GLOBAL(0x005BDD30);
    ACCESS(this, 4, 4) = GLOBAL(0x005BDD2C);
}

// address: 0x0045050B
B_SectorListNode::~B_SectorListNode()
{
    ACCESS(this, 4, 4) = GLOBAL(0x005BDD2C);
    STACKVAR(-20, 4) = reinterpret_cast<any_int32>(this) + 0x00000004;
    if (ACCESS(STACKVAR(-20, 4), 16, 4) == 0x00000000)
    {
        goto l004505C9;
    }
    if (0x00000000 == 0x00000000)
    {
        goto l00450596;
    }
    unsigned int unknown_loc_04 = 0;
    goto l00450556;
l0045054D:
    unknown_loc_04++;
l00450556:
    if (unknown_loc_04 < reinterpret_cast<unsigned int>(ACCESS(STACKVAR(-20, 4), 8, 4)))
    {
        STACKVAR(-12, 4) = ACCESS(ARRPTR(ACCESS(STACKVAR(-20, 4), 4, 4), 4, unknown_loc_04, 0), 0, 4);
        STACKVAR(-8, 4) = STACKVAR(-12, 4);
        if (STACKVAR(-8, 4) != 0x00000000)
        {
            STACKVAR(-52, 4) = STACKVAR(-8, 4)->(ACCESS(ACCESS(STACKVAR(-8, 4), 0, 4), 0, 4))(0x00000001);
        }
        else
        {
            STACKVAR(-52, 4) = 0x00000000;
        }
        goto l0045054D;
    }
l00450596:
    STACKVAR(-16, 4) = ACCESS(STACKVAR(-20, 4), 4, 4);
    unknown_function_005BBD3D(STACKVAR(-16, 4));
    ACCESS(STACKVAR(-20, 4), 4, 4) = 0x00000000;
    ACCESS(STACKVAR(-20, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-20, 4), 16, 4) = 0x00000000;
l004505C9:
    if (this != nullptr)
    {
        STACKVAR(-44, 4) = reinterpret_cast<any_int32>(this) + 0x00000004;
    }
    else
    {
        STACKVAR(-44, 4) = 0x00000000;
    }
    ACCESS(STACKVAR(-44, 4), 0, 4) = GLOBAL(0x005BDB7C);
    if (ACCESS(STACKVAR(-44, 4), 16, 4) == 0x00000000)
    {
        goto l00450699;
    }
    STACKVAR(-40, 4) = ACCESS(STACKVAR(-44, 4), 20, 4);
    if (ACCESS(STACKVAR(-44, 4), 16, 4) == 0x00000000)
    {
        goto l00450699;
    }
    if (STACKVAR(-40, 4) == 0x00000000)
    {
        goto l00450666;
    }
    unsigned int unknown_loc_18 = 0;
    goto l00450626;
l0045061D:
    unknown_loc_18++;
l00450626:
    if (unknown_loc_18 < reinterpret_cast<unsigned int>(ACCESS(STACKVAR(-44, 4), 8, 4)))
    {
        STACKVAR(-32, 4) = ACCESS(ARRPTR(ACCESS(STACKVAR(-44, 4), 4, 4), 4, unknown_loc_18, 0), 0, 4);
        STACKVAR(-28, 4) = STACKVAR(-32, 4);
        if (STACKVAR(-28, 4) != 0x00000000)
        {
            STACKVAR(-56, 4) = STACKVAR(-28, 4)->(ACCESS(ACCESS(STACKVAR(-28, 4), 0, 4), 0, 4))(0x00000001);
        }
        else
        {
            STACKVAR(-56, 4) = 0x00000000;
        }
        goto l0045061D;
    }
l00450666:
    STACKVAR(-36, 4) = ACCESS(STACKVAR(-44, 4), 4, 4);
    unknown_function_005BBD3D(STACKVAR(-36, 4));
    ACCESS(STACKVAR(-44, 4), 4, 4) = 0x00000000;
    ACCESS(STACKVAR(-44, 4), 8, 4) = 0x00000000;
    ACCESS(STACKVAR(-44, 4), 16, 4) = 0x00000000;
l00450699:
    ACCESS(this, 0, 4) = GLOBAL(0x005BDD0C);
    gbl_node_count--;
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

// address: 0x0045201F
void LeafNode::CollectSectorsAtPoint(const B_Vector &localPos, B_OctTreeSectorsList *outList, double halfSize)
{
    if (this->sectors->lastQueryId != reinterpret_cast<int>(gbl_oct_tree_query_id) && this->sectors->isActive != 0)
    {
        this->sectors->lastQueryId = reinterpret_cast<int>(gbl_oct_tree_query_id);
        if (outList->size < 512)
        {
            ACCESS(ARRPTR(outList, 4, outList->size, 4), 0, 4) = this->sectors;
            outList->size++;
        }
    }
}

// address: 0x00452191
void B_SectorListNode::CollectSectorsAtPoint(const B_Vector &localPos, B_OctTreeSectorsList *outList, double halfSize)
{
    unsigned int unknown_loc_04 = 0;
    goto l004521AD;
l004521A4:
    unknown_loc_04++;
l004521AD:
    if (unknown_loc_04 < reinterpret_cast<unsigned int>(ACCESS(this, 12, 4)))
    {
        if (reinterpret_cast<unsigned int>(ACCESS(ACCESS(ARRPTR(ACCESS(this, 8, 4), 4, unknown_loc_04, 0), 0, 4), 84, 4)) != gbl_oct_tree_query_id && ACCESS(ACCESS(ARRPTR(ACCESS(this, 8, 4), 4, unknown_loc_04, 0), 0, 4), 88, 4) != 0x00000000)
        {
            ACCESS(ACCESS(ARRPTR(ACCESS(this, 8, 4), 4, unknown_loc_04, 0), 0, 4), 84, 4) = gbl_oct_tree_query_id;
            if (outList->size < 512)
            {
                ACCESS(ARRPTR(outList, 4, outList->size, 4), 0, 4) = ACCESS(ARRPTR(ACCESS(this, 8, 4), 4, unknown_loc_04, 0), 0, 4);
                outList->size++;
            }
        }
        goto l004521A4;
    }
}

// address: 0x00453067
void B_OctTree::FindSectorsAtPoint(const B_Vector &worldPos, B_OctTreeSectorsList *outList) const
{
    outList->size = 0;
    *reinterpret_cast<B_Vector *>(LOCAL(-24)) = worldPos - this->m_center;
    gbl_oct_tree_query_id++;
    if (this->m_root != nullptr && this->m_halfSize + reinterpret_cast<double>(ACCESS(GLOBAL(0x005BDB88), 0, 8)) > fabs(reinterpret_cast<double>(STACKVAR(-24, 8))) && this->m_halfSize + reinterpret_cast<double>(ACCESS(GLOBAL(0x005BDB88), 0, 8)) > fabs(reinterpret_cast<double>(STACKVAR(-16, 8))) && this->m_halfSize + reinterpret_cast<double>(ACCESS(GLOBAL(0x005BDB88), 0, 8)) > fabs(reinterpret_cast<double>(STACKVAR(-8, 8))))
    {
        this->m_root->(ACCESS(ACCESS(this->m_root, 0, 4), 12, 4))(LOCAL(-24), outList, this->m_halfSize);
    }
}

// address: 0x00453264
B_OctTreeSectorsList::B_OctTreeSectorsList()
{
    this->size = 0;
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
