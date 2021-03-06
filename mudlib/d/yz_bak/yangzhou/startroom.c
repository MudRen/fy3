// By Mr.music  yangzhou's 明月酒楼

inherit ROOM;

void create()
{
        set("short", "明月酒楼");
        set("long", @LONG
        这里就是扬州城里名扬四海的明月酒楼，这里的名点每年会
作为贡品飞马送京，历代王候将相、豪客名流无不至此亲临品尝。厅
内人声鼎沸，酒香扑鼻，使你感到好象有点饿了。楼上是客栈，外地
来的客人也可以在此休息过宿，三楼是巫师们的会客厅，想到什么好
的意见和建议，请在三楼访客留言板留言。

LONG
        );

        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_sleep_room",1);

        set("item_desc", ([
                "paizi" : "楼上卧房，每夜一两白银。\n",
                         ]));

        set("objects", ([
                __DIR__"npc/xiaoer" : 1,
                __DIR__"npc/weixiaobao"  : 1,
        ]));

        set("exits", ([
                "east" : __DIR__"pishijie3",
                "up" : __DIR__"mingyue2",
        ]));

        setup();
}

void init()
{
add_action("to_hankou","quhankou");
add_action("do_gui","gui");
add_action("do_gui","kneel");
}

int do_gui()
{
return 1;
}

int to_hankou()
{

tell_object(this_player(),"[1;33m伙计说：正好后院有车到汉口，带你一程吧.[0;37m\n");

say(this_player()->query("name")+"跟着小伙计到后院了。\n");


this_player()->move(__DIR__"houyuan");


return 1;
}


int valid_leave(object me, string dir)
{

//         if( ( ! wizardp(me) ) && dir == "up" ) return 
//   notify_fail("店小二挡在楼梯前，陪笑道，楼上正装修，您老还是大厅坐吧!\n");

        if ( !me->query_temp("rent_paid") && dir == "up" && !wizardp(me))
        return 
notify_fail("店小二挡在楼梯前，奸笑道：楼上是雅座，您老还是大厅坐吧!\n");

// if who upstair for post in wizroom , back money to it.
if( ! wizardp(me) )
    {
       if( me->query_temp("post_ok_la")  && dir == "out")
        {
          say("店小二对"+me->query("name")+"鞠个躬连声道：大爷慢走！\n");
          write("店小二悄悄把你拉到一边. \n");
          write("店小二小声说道：不知您是巫师的朋友，还望您老海涵!\n");
          write("店小二乘人不注意，塞了二两银子给你. \n");
          clone_object("/obj/money/silver")->move(me);
          clone_object("/obj/money/silver")->move(me);
//error:           me->add_money("silver", 2);
          me->delete_temp("post_ok_la");
         }
     }

        return ::valid_leave(me, dir);
}
