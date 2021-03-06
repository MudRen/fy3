// Room: /u/xxy/room/xixiang
inherit ROOM;

void create ()
{
  set ("short", "明月池");
  set ("long", @LONG
明月池,地势高爽,脚下峰岚起伏,展视平畴,一望无垠,此处原是
一个天然水泉,附近的僧人把池子(quan)改造成六边形,池边的岩石
上,有一个奇怪的大象脚印,传说,普贤骑象登山,曾在池中汲水洗象
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/monkey.c" : 1,
]));
set("outdoors","/d/emei");
  set("item_desc", ([ /* sizeof() == 1 */
  "quan" : "每当月明之时,池水总是碧澄澄的没有一丝风吹的皱纹,皎皎的
月影,恰如一块无暇的玉盘,落在池水中间,这就是有名的'象池夜月'.
池水清澈无比,看来可以喝(drink).
",
]));
  set("exits", ([ /* sizeof() == 2 */
  "eastdown" : __DIR__"fohushi",
  "northup" : __DIR__"uproad",
]));

  setup();
}
void init()
{
    add_action("do_drink", "drink");
    add_action("do_jump","jump");
}

int do_drink(string sss)
{

object ob;
ob=this_player();
if ((sss!="water")&&(sss!="quan"))
   return 0;
 say(ob->query("name")+"趴在水池边，一口气喝了够饱. \n");
 tell_object(ob,"你趴在水池边，一口气喝了够饱. \n");
 ob->set("water",((int)ob->query("str")-10)*10+200);

  return 1;
 }
int do_jump(string arg)
{
    if(arg!="down") return 0;
 
    message_vision("随着一声惊叫,$N双手挥舞着掉入冰冷的池水中。\n", this_player());
    this_player()->move(__DIR__"shuitan"); 

    return 1;
}
