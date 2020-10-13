#ifndef EMIS_H
#define EMIS_H
#include "manager_view.h"

class EMIS
{
    ManagerView* mgrView;
    static EMIS emis;
    EMIS(void);
    EMIS(EMIS& that) {}
public:
    static EMIS& getOBJ(void);
    ~EMIS(void);
    void emisMenu(void);
};

#endif//EMIS_H