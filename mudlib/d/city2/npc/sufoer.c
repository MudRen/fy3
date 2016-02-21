inherit KZZNPC;
inherit F_VENDOR;
string query_save_file() { return DATA_DIR+"npc/苏佛儿";}
void create()
{
#include <kzznpc.h>
set("area_name","京都客栈");
set("area_file","/d/city2/kedian.c");
set("vendor_goods",([
"包子":     "/d/yangzhou/npc/obj/baozi",
"酒壶":     "/d/yangzhou/npc/obj/jiuhu",
"鸡腿":     "/obj/std/food/jitui",
"盐水鹅" :  "/d/yangzhou/npc/obj/yanshuie",
"花生米" :  "/d/yangzhou/npc/obj/huashengmi",
])); 
	setup();
}
void init()
{
	::init();
  add_action("do_vendor_list","list");
  }         
