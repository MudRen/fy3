//This xuedao170 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "秘室");
  set("long",@LONG
此处的石台上架着---赤血魔刀。
LONG
  );
  set("exits", ([ /* sizeof() == 1 */ 
      "south" : __DIR__"xuedao169",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/2");
  setup();
  replace_program(ROOM);//如果没有init函数请不要删除这句话

}
