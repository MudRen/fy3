//This xuedao48 room file by mapmaker

inherit ROOM;

void create()
{
  set("short", "血河东岸");
  set("long",@LONG
这是一间空空荡荡的房间。
LONG
  );
  set("exits", ([ /* sizeof() == 2 */ 
      "west" : __DIR__"xuedao49",
      "southeast" : __DIR__"xuedao47",
      ]));
  set("no_clean_up", 0);
  set("outdoors","xuedaomen/1");
  setup();
  replace_program(ROOM);//如果没有init函数请不要删除这句话

}
