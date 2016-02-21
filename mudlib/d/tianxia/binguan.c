// Room: /d/new/tianxia/binguan
inherit ROOM;

void create()
{
  set ("short", "迎宾馆");
  set ("long", @LONG
满天的云彩被宾馆门前两棵高大的银杏树遮住了大半,浓密的绿茵把一
半的枝叶直接深入宾馆内部.平整的麻石一直铺到红色的大门口.黑底红字
的匾额系用朱砂写就.北面是一片空场.
LONG);

  set("outdoors", "/d/new");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"binguan1",
  "north" : __DIR__"1guan5",
]));
  setup();
}
