// dou_peng.c
// 97.7.14 by Aug

#include <armor.h>

inherit F_CLOTH;

void create()
{
	set_name("����", ({ "dou peng" }) );
	set_weight(1500);
	setup_cloth();

	if( !clonep() ) {
		set("unit", "��");
		set("value", 1000);
		set("long", "һ�����ϺõĶ����ƳɵĴ�ɫ����\n");
		set("wear_as", "cloth");
		set("apply_armor/cloth", ([
			"armor": 5,
		]));
	}

	setup();
}