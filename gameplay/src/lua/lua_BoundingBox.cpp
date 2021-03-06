#include "Base.h"
#include "ScriptController.h"
#include "lua_BoundingBox.h"
#include "Base.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "Plane.h"

namespace gameplay
{

void luaRegister_BoundingBox()
{
    const luaL_Reg lua_members[] = 
    {
        {"getCenter", lua_BoundingBox_getCenter},
        {"getCorners", lua_BoundingBox_getCorners},
        {"intersects", lua_BoundingBox_intersects},
        {"isEmpty", lua_BoundingBox_isEmpty},
        {"max", lua_BoundingBox_max},
        {"merge", lua_BoundingBox_merge},
        {"min", lua_BoundingBox_min},
        {"set", lua_BoundingBox_set},
        {"transform", lua_BoundingBox_transform},
        {NULL, NULL}
    };
    const luaL_Reg lua_statics[] = 
    {
        {"empty", lua_BoundingBox_static_empty},
        {NULL, NULL}
    };
    std::vector<std::string> scopePath;

    ScriptUtil::registerClass("BoundingBox", lua_members, lua_BoundingBox__init, lua_BoundingBox__gc, lua_statics, scopePath);
}

static BoundingBox* getInstance(lua_State* state)
{
    void* userdata = luaL_checkudata(state, 1, "BoundingBox");
    luaL_argcheck(state, userdata != NULL, 1, "'BoundingBox' expected.");
    return (BoundingBox*)((ScriptUtil::LuaObject*)userdata)->instance;
}

int lua_BoundingBox__gc(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                void* userdata = luaL_checkudata(state, 1, "BoundingBox");
                luaL_argcheck(state, userdata != NULL, 1, "'BoundingBox' expected.");
                ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)userdata;
                if (object->owns)
                {
                    BoundingBox* instance = (BoundingBox*)object->instance;
                    SAFE_DELETE(instance);
                }
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox__gc - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox__init(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 0:
        {
            void* returnPtr = (void*)new BoundingBox();
            if (returnPtr)
            {
                ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                object->instance = returnPtr;
                object->owns = true;
                luaL_getmetatable(state, "BoundingBox");
                lua_setmetatable(state, -2);
            }
            else
            {
                lua_pushnil(state);
            }

            return 1;
            break;
        }
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA || lua_type(state, 1) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<BoundingBox> param1 = ScriptUtil::getObjectPointer<BoundingBox>(1, "BoundingBox", true);

                void* returnPtr = (void*)new BoundingBox(*param1);
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = true;
                    luaL_getmetatable(state, "BoundingBox");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox__init - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA || lua_type(state, 1) == LUA_TNIL) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(1, "Vector3", true);

                // Get parameter 2 off the stack.
                ScriptUtil::LuaArray<Vector3> param2 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                void* returnPtr = (void*)new BoundingBox(*param1, *param2);
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = true;
                    luaL_getmetatable(state, "BoundingBox");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox__init - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 0, 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox_getCenter(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                BoundingBox* instance = getInstance(state);
                void* returnPtr = (void*)new Vector3(instance->getCenter());
                if (returnPtr)
                {
                    ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                    object->instance = returnPtr;
                    object->owns = true;
                    luaL_getmetatable(state, "Vector3");
                    lua_setmetatable(state, -2);
                }
                else
                {
                    lua_pushnil(state);
                }

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_getCenter - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", false);

                BoundingBox* instance = getInstance(state);
                instance->getCenter(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_getCenter - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox_getCorners(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TTABLE || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", false);

                BoundingBox* instance = getInstance(state);
                instance->getCorners(param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_getCorners - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox_intersects(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<BoundingBox> param1 = ScriptUtil::getObjectPointer<BoundingBox>(2, "BoundingBox", true);

                BoundingBox* instance = getInstance(state);
                bool result = instance->intersects(*param1);

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<BoundingSphere> param1 = ScriptUtil::getObjectPointer<BoundingSphere>(2, "BoundingSphere", true);

                BoundingBox* instance = getInstance(state);
                bool result = instance->intersects(*param1);

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Frustum> param1 = ScriptUtil::getObjectPointer<Frustum>(2, "Frustum", true);

                BoundingBox* instance = getInstance(state);
                bool result = instance->intersects(*param1);

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Plane> param1 = ScriptUtil::getObjectPointer<Plane>(2, "Plane", true);

                BoundingBox* instance = getInstance(state);
                float result = instance->intersects(*param1);

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Ray> param1 = ScriptUtil::getObjectPointer<Ray>(2, "Ray", true);

                BoundingBox* instance = getInstance(state);
                float result = instance->intersects(*param1);

                // Push the return value onto the stack.
                lua_pushnumber(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_intersects - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox_isEmpty(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 1:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA))
            {
                BoundingBox* instance = getInstance(state);
                bool result = instance->isEmpty();

                // Push the return value onto the stack.
                lua_pushboolean(state, result);

                return 1;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_isEmpty - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 1).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox_max(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 2)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
        lua_error(state);
    }

    BoundingBox* instance = getInstance(state);
    if (lua_gettop(state) == 2)
    {
        // Get parameter 2 off the stack.
        ScriptUtil::LuaArray<Vector3> param2 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

        instance->max = *param2;
        return 0;
    }
    else
    {
        void* returnPtr = (void*)new Vector3(instance->max);
        if (returnPtr)
        {
            ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
            object->instance = returnPtr;
            object->owns = true;
            luaL_getmetatable(state, "Vector3");
            lua_setmetatable(state, -2);
        }
        else
        {
            lua_pushnil(state);
        }

        return 1;
    }
}

int lua_BoundingBox_merge(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<BoundingSphere> param1 = ScriptUtil::getObjectPointer<BoundingSphere>(2, "BoundingSphere", true);

                BoundingBox* instance = getInstance(state);
                instance->merge(*param1);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<BoundingBox> param1 = ScriptUtil::getObjectPointer<BoundingBox>(2, "BoundingBox", true);

                BoundingBox* instance = getInstance(state);
                instance->merge(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_merge - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox_min(lua_State* state)
{
    // Validate the number of parameters.
    if (lua_gettop(state) > 2)
    {
        lua_pushstring(state, "Invalid number of parameters (expected 1 or 2).");
        lua_error(state);
    }

    BoundingBox* instance = getInstance(state);
    if (lua_gettop(state) == 2)
    {
        // Get parameter 2 off the stack.
        ScriptUtil::LuaArray<Vector3> param2 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

        instance->min = *param2;
        return 0;
    }
    else
    {
        void* returnPtr = (void*)new Vector3(instance->min);
        if (returnPtr)
        {
            ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
            object->instance = returnPtr;
            object->owns = true;
            luaL_getmetatable(state, "Vector3");
            lua_setmetatable(state, -2);
        }
        else
        {
            lua_pushnil(state);
        }

        return 1;
    }
}

int lua_BoundingBox_set(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<BoundingBox> param1 = ScriptUtil::getObjectPointer<BoundingBox>(2, "BoundingBox", true);

                BoundingBox* instance = getInstance(state);
                instance->set(*param1);
                
                return 0;
            }
            else if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<BoundingSphere> param1 = ScriptUtil::getObjectPointer<BoundingSphere>(2, "BoundingSphere", true);

                BoundingBox* instance = getInstance(state);
                instance->set(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_set - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        case 3:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL) &&
                (lua_type(state, 3) == LUA_TUSERDATA || lua_type(state, 3) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Vector3> param1 = ScriptUtil::getObjectPointer<Vector3>(2, "Vector3", true);

                // Get parameter 2 off the stack.
                ScriptUtil::LuaArray<Vector3> param2 = ScriptUtil::getObjectPointer<Vector3>(3, "Vector3", true);

                BoundingBox* instance = getInstance(state);
                instance->set(*param1, *param2);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_set - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2 or 3).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox_static_empty(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 0:
        {
            void* returnPtr = (void*)&(BoundingBox::empty());
            if (returnPtr)
            {
                ScriptUtil::LuaObject* object = (ScriptUtil::LuaObject*)lua_newuserdata(state, sizeof(ScriptUtil::LuaObject));
                object->instance = returnPtr;
                object->owns = false;
                luaL_getmetatable(state, "BoundingBox");
                lua_setmetatable(state, -2);
            }
            else
            {
                lua_pushnil(state);
            }

            return 1;
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 0).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

int lua_BoundingBox_transform(lua_State* state)
{
    // Get the number of parameters.
    int paramCount = lua_gettop(state);

    // Attempt to match the parameters to a valid binding.
    switch (paramCount)
    {
        case 2:
        {
            if ((lua_type(state, 1) == LUA_TUSERDATA) &&
                (lua_type(state, 2) == LUA_TUSERDATA || lua_type(state, 2) == LUA_TNIL))
            {
                // Get parameter 1 off the stack.
                ScriptUtil::LuaArray<Matrix> param1 = ScriptUtil::getObjectPointer<Matrix>(2, "Matrix", true);

                BoundingBox* instance = getInstance(state);
                instance->transform(*param1);
                
                return 0;
            }
            else
            {
                lua_pushstring(state, "lua_BoundingBox_transform - Failed to match the given parameters to a valid function signature.");
                lua_error(state);
            }
            break;
        }
        default:
        {
            lua_pushstring(state, "Invalid number of parameters (expected 2).");
            lua_error(state);
            break;
        }
    }
    return 0;
}

}
