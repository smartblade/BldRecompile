#include <App/camera.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00418E69
* VC++ mangling:          ?SetTravelingView@B_Camera@@QAEHHH@Z
*/

int B_Camera::SetTravelingView(int s_type, int t_type)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004195CE
* VC++ mangling:          ?SetPersonView@B_Camera@@QAEHPBD@Z
*/

int B_Camera::SetPersonView(const char *person_name)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041A86B
* VC++ mangling:          ?Read3dsMaxAnimation@B_Camera@@QAEHPBDHH@Z
*/

int B_Camera::Read3dsMaxAnimation(
    const char *cam_file_name, int i_unknown, int num_frames)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041AD83
* VC++ mangling:          ?DeleteEvent@B_Camera@@QAEHH@Z
*/

int B_Camera::DeleteEvent(int frame)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0041AE6D
* VC++ mangling:          ?AddEvent@B_Camera@@QAEXHPAUPyObject@@@Z
*/

void B_Camera::AddEvent(int frame, PyObject *func)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004201E8
* VC++ mangling:          ?AddSourceNode@B_Camera@@QAEHNABVB_Vector@@@Z
*/

int B_Camera::AddSourceNode(double time, const B_Vector &position)
{
}
