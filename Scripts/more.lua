#!/usr/bin/lua5.1

function LoadScript(me)
    -- Log:print("LoadScript !")
end

local timer = 200
function UpdateAI(me, diff)
    if timer <= diff then
        me:CheckBonusCross(2)
        timer = 200
    else
        timer = timer - diff;
    end
end

function HandleHit(me, by)
    Log:print("More catch")
    me:Despawn()
end

function HandleCross(me, by)
    Log:print("CROSSED")
    by:AddMaxBombCount(1)
    me:Despawn()
end
