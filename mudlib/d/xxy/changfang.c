// Room: /d/xxy/changfang 
inherit ROOM; 
 
void create() 
{ 
  set ("short", "大敞房");
  set ("long", @LONG
一间很大的房间,里面是两溜长通铺,地上还铺着许多稻草,那是因为人
多,许多人只能在地上凑合.房间中发出一股汗酸味.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yongdao2",
]));
  set("sleep_room",1);
  setup();
}
