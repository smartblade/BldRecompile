

/*
* Module:                 Blade.exe
* Entry point:            0x0046AB6A
*/

int GetAnimationDuration(const char *animation_name, double *duration)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046AC16
*/

int RStepEvents(const char *s_unknown1, const char *s_unknown2)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046AEEC
*/

int LStepEvents(const char *s_unknown1, const char *s_unknown2)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046B885
*/

int LoadSampledAnimation(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046C4D9
*/

int CreateFCAnimation(
        const char *file, const char *internal_name, int n_armonics
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046CAFB
*/

int CreateDFCAnimation(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046D1F0
*/

int AddRStepEvent(const char *animation_name, double d_unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046D3DE
*/

int AddLStepEvent(const char *animation_name, double d_unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046D5CC
*/

int AddRReleaseEvent(const char *animation_name, double d_unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046D7BA
*/

int AddLReleaseEvent(const char *animation_name, double d_unknown)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046D9A8
*/

void AddAnmEvent(const char *anm_name, const char *event_name, double event_frame)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046E1AB
*/

void AddStopTests(const char *animation_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046E4AC
*/

void AddFloorCTolerance(const char *animation_name, double tolerance)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046E57A
*/

int AddTranTime(
        const char *biped_name, const char *next_anm , const char *prev_anm,
        double time, int unknown
)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046E93B
*/

int CheckAnims()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0046EBFD
*/

int GiveAnims(const char *race_name)
{
}
