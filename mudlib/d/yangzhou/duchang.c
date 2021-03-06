// Room: /u/swordman/yangzhou/duchang
inherit ROOM;

void create ()
{
  set ("short", "扬州赌坊");
  set ("long", @LONG
这里是赌场的大堂，从北边房间里传出来吆五喝六的赌博声。场里
笑声哭声叫骂声，加上烟味酒味脂粉味混乱到了极点。
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/duchangxiaoer" : 1,
  __DIR__"npc/likui" : 1,
  __DIR__"npc/weichunhua" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nongtang",
  "north" : __DIR__"duchangx",
]));
  set("light_up", 1);

  setup();
}
int valid_leave(object me,string dir)
{
        string banghui;
        object ob;

        ob=present("likui",this_object());
        if(!objectp(ob) || !living(ob))
                return ::valid_leave(me,dir);
        banghui=(string)me->query("banghui");
        if(me->query_temp("oldsix/can_leave"))  {
                me->delete_temp("oldsix/can_leave");
                return ::valid_leave(me,dir);
        }
        if(banghui && banghui==(string)ob->query("banghui"))
                return ::valid_leave(me,dir);
        if(dir!="north")        return ::valid_leave(me,dir);
        return notify_fail("赌场的规矩你懂不懂？！\n");
}
