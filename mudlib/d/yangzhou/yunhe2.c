// music yangzhou's 运河 2

inherit ROOM;

void go_ahead(object );

void create()
{
  set ("short", "运河");
  set ("long", @LONG
	你泛舟在运河上，坐在船头，微风习习，船下碧波荡漾，你可能感
到有点儿疲倦了，两岸都是无边的旷野，来往船只越来越少，你看着两岸的
黄土，心里一阵空虚。
LONG
    );

  set("outdoors", "/d/yangzhou");
  setup();
}

void init()
{
    call_out("go_ahead",20,this_player() );
    add_action("do_hua", "hua");
}

int do_hua()
{
tell_object( this_player() ,"你用力划了一段路. \n" );
this_player()->add("kee",-10);
return 1;
}

void go_ahead(object me)
{
if( (me->query_temp("yz_sz")) ==2 )
    {
    me->move("/d/yangzhou/yunhe1");
    return;
    }
if( (me->query_temp("yz_sz")) ==1 )
    {
    me->move("/d/suzhou/yunhe3");
    return;
    }
    // if not 1,2 ?
    me->move("/d/yangzhou/qiaoxia");
return;
}


