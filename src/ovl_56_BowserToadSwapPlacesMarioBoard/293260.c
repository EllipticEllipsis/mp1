#include "common.h"
#include "293260.h"

Vec3f D_800F6DB0_293A30 = {0.0f, -190.0f, -500.0f};
Vec3f D_800F6DBC_293A3C = {0.0f, -190.0f, -500.0f};

s32 D_800F6DC8_293A48[] = {0x00000001, 0x000A006A};
s32 D_800F6DD0_293A54[] = {0x00000001, 0x00070004};

void func_800F65E0_293260(void) {
    D_800F6DF0 = D_800ED5DD;
    func_8005CF30(50, 10);
    func_800F6CE8_293968();
    func_800F6B1C_29379C();
    func_800544E4();
    func_800546B4(0, gPlayers[0].turn_status);
    func_800546B4(1, gPlayers[1].turn_status);
    func_800546B4(2, gPlayers[2].turn_status);
    func_800546B4(3, gPlayers[3].turn_status);
    InitProcess(func_800F692C_2935AC, 0x300, 0, 0);
    func_8005D384(0x1000, 0, 0, -1, &func_800F6AC8_293748);
    func_80072644(4, 16);
}

//very odd need for temps?
void func_800F66AC_29332C(f32 arg0) {
    unk_Struct03* temp_s0;
    unk_Struct03* var_s0;
    Vec3f* temp;

    if (D_800ED154.unk_00 != 0) {
        temp_s0 = D_800F6DF4;
        temp = &D_800F6DBC_293A3C;
        temp_s0->coords.x = temp->x + (func_80088060(arg0 * 0.017453292519943295) * 200.0f);
        temp_s0 = D_800F6DF4;
        temp_s0->coords.z = (func_800855C0(arg0 * 0.017453292519943295) * 200.0f) + D_800F6DBC_293A3C.z;
        temp_s0 = D_800F6DF4;
        temp_s0->unk_18.x = func_80088060(arg0 * 0.017453292519943295);
        temp_s0 = D_800F6DF4;
        temp_s0->unk_18.z = func_800855C0(arg0 * 0.017453292519943295);
        temp_s0 = D_800F6DFC;
        temp_s0->unk_18.x = func_80088060(arg0 * 0.017453292519943295);
        temp_s0 = D_800F6DFC;
        temp_s0->unk_18.z = func_800855C0(arg0 * 0.017453292519943295);
        temp_s0 = D_800F6DF8;
        temp_s0->coords.x = temp->x - (func_80088060(arg0 * 0.017453292519943295) * 200.0f);
        temp_s0 = D_800F6DF8;
        temp_s0->coords.z = temp->z - (func_800855C0(arg0 * 0.017453292519943295) * 200.0f);
        temp_s0 = D_800F6DF8;
        temp_s0->unk_18.x = -func_80088060(arg0 * 0.017453292519943295);
        var_s0 = D_800F6DF8;
        var_s0->unk_18.z = -func_800855C0(arg0 * 0.017453292519943295);
    } else {
        temp_s0 = D_800F6DF8;
        temp = &D_800F6DBC_293A3C;
        temp_s0->coords.x = (func_80088060(arg0 * 0.017453292519943295) * 200.0f) + temp->x;
        temp_s0 = D_800F6DF8;
        temp_s0->coords.z = (func_800855C0(arg0 * 0.017453292519943295) * 200.0f) + D_800F6DBC_293A3C.z;
        temp_s0 = D_800F6DF8;
        temp_s0->unk_18.x = func_80088060(arg0 * 0.017453292519943295);
        temp_s0 = D_800F6DF8;
        temp_s0->unk_18.z = func_800855C0(arg0 * 0.017453292519943295);
        temp_s0 = D_800F6DFC;
        temp_s0->unk_18.x = func_80088060(arg0 * 0.017453292519943295);
        temp_s0 = D_800F6DFC;
        temp_s0->unk_18.z = func_800855C0(arg0 * 0.017453292519943295);
        temp_s0 = D_800F6DF4;
        temp_s0->coords.x = temp->x - (func_80088060(arg0 * 0.017453292519943295) * 200.0f);
        temp_s0 = D_800F6DF4;
        temp_s0->coords.z = D_800F6DBC_293A3C.z - (func_800855C0(arg0 * 0.017453292519943295) * 200.0f);
        temp_s0 = D_800F6DF4;
        temp_s0->unk_18.x = -func_80088060(arg0 * 0.017453292519943295);
        var_s0 = D_800F6DF4;
        var_s0->unk_18.z = -func_800855C0(arg0 * 0.017453292519943295);
    }
}

void func_800F692C_2935AC(void) {
    s32 i;
    f32 var_f20;
    
    SleepProcess(26);
    PlaySound(226);

    if (D_800ED154.unk_00 != 0) {
        PlaySound(1131);
    } else {
        PlaySound(1127);
    }
    
    for (var_f20 = 0.0f; var_f20 >= -180.0f; var_f20 -= 5.0f) {
        func_800F66AC_29332C(var_f20);
        SleepVProcess();
    }

    PlaySound(228);
    
    D_800ED154.unk_00 = (D_800ED154.unk_00 + 1) & 1;
    
    if (D_800ED154.unk_00 == 0) {
        PlaySound(1126);
        func_8003E81C(D_800F6DF8, 0, 2);
        
        for (i = 0; i < 2; i++) {
            func_8004F00C(D_800F6DF8, 40.0f, -5.0f);
            func_8004F044(D_800F6DF8);            
        }

    } else {
        PlaySound(1130);
        func_8003E81C(D_800F6DF4, 0, 2);
        SleepProcess(40);
    }
    
    D_800F5144 = 1;
    
    while(1) {
        SleepVProcess();
    }
    
}

void func_800F6A84_293704(void) {
    if (func_80072718() == 0) {
        func_800F6D88_293A08();
        func_800F6CB0_293930();
        func_80054654();
        func_8005DFB8(1);
    }
}

void func_800F6AC8_293748(Object* arg0) {
    if (D_800F5144 != 0) {
        if (D_800ED154.unk_00 != 0) {
            func_800726AC(3, 16);
        } else {
            func_800726AC(2, 16);
        }
        arg0->func_ptr = &func_800F6A84_293704;
    }
}

void func_800F6B1C_29379C(void) {
    func_8003DAA8();
    D_800F6DFC = func_8003DBE0(20, NULL);
    VEC3F_COPY_TO_OBJ(D_800F6DFC, D_800F6DB0_293A30);
    D_800F6DFC->unk_24 = D_800F6DFC->unk_28 = D_800F6DFC->unk_2C = 1.5f;
    func_80025F60(*D_800F6DFC->unk_3C->unk_40, 0);
    D_800F6DF4 = func_8003DBE0(108, D_800F6DC8_293A48);
    D_800F6DF4->coords.x = D_800F6DBC_293A3C.x;
    D_800F6DF4->coords.y = D_800F6DBC_293A3C.y;
    D_800F6DF4->coords.z = D_800F6DBC_293A3C.z + 200.0f;
    D_800F6DF4->unk_24 = D_800F6DF4->unk_28 = D_800F6DF4->unk_2C = 1.5f;
    D_800F6DF8 = func_8003DBE0(7, D_800F6DD0_293A54);
    D_800F6DF8->coords.x = D_800F6DBC_293A3C.x;
    D_800F6DF8->coords.y = D_800F6DBC_293A3C.y;
    D_800F6DF8->coords.z = D_800F6DBC_293A3C.z + 200.0f;
    func_800258EC(*D_800F6DF4->unk_40->unk_40, 0x180, 0x80);
    func_800258EC(*D_800F6DF8->unk_40->unk_40, 0x180, 0x80);
    func_80025AD4(*D_800F6DF4->unk_40->unk_40);
    func_80025AD4(*D_800F6DF8->unk_40->unk_40);
    func_800F66AC_29332C(0);
}

void func_800F6CB0_293930(void) {
    func_8003E694(D_800F6DF4);
    func_8003E694(D_800F6DF8);
    func_8003E694(D_800F6DFC);
}


void func_800F6CE8_293968(void) {
    func_800178A0(1);
    func_80017660(0, 0.0f, 0.0f, 320.0f, 240.0f);
    func_800176C4(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    func_80049E70(&D_FE2310);
    func_80049F4C(51);
}

void func_800F6D88_293A08(void) {
    func_8004A140();
    func_80049F0C();
}

