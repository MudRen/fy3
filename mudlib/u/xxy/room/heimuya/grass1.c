inherit ROOM;
 
void create()
{
        set("short", "�ݵ�");
        set("long",@LONG
������һƬ�ݵء��ݵض�����һƬĹ�ء�
LONG );

        set("exits", ([
  "east"    : __DIR__"mudi",
  "south"    : __DIR__"fen0", 
  "north"    :__DIR__"grass2",
]));
         set("outdoors", "inn");    
         setup();
}