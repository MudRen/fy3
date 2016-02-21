// Room: /d/new/tianxia/bridge1
inherit ROOM;

void create()
{
  set ("short", "小石桥");
  set ("long", @LONG
一根长长的石梁深入洞窟深处,石梁下是水流汹涌的地下暗河.石梁
上滑腻腻的,布满了苔藓.可要小心一点.
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"incave1",
  "south" : __DIR__"incave4",
]));
  setup();
}
int valid_leave(object ob,string dir)
{
   if (random(10)>6)    {
   	message_vision("$N惊叫一声,脚下一滑,掉下水去.\n",ob);
   	ob->move(__DIR__"river1");
   	return notify_fail("");
   }
 return ::valid_leave(ob,dir);
 }
   	