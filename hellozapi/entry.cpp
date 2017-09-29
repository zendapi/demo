// Copyright 2017-2018 zzu_softboy <zzu_softboy@163.com>
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Created by softboy on 2017/09/22.

#include "zapi/ZendApi.h"
#include "defs.h"

using zapi::lang::Constant;
using zapi::lang::ValueArgument;
using zapi::lang::Class;
using zapi::lang::Type;
using zapi::lang::Namespace;

extern "C" {

ZAPI_DECL_EXPORT void *get_module() 
{
   static zapi::lang::Extension hellozapi("hellozapi", "1.0");
   Constant hellozapiVersionConst("HELLO_ZAPI_VERSION", 0x010002);
   Constant hellozapiNameConst("HELLO_ZAPI_NAME", "Hello zendAPI!");
   Constant helloDebugModeConst("HELLO_DEBUG_MODE", true);
   Constant helloPiConst("HELLO_ZAPI_PI", 3.14);
   hellozapi.registerConstant(std::move(hellozapiVersionConst));
   hellozapi.registerConstant(std::move(hellozapiNameConst));
   hellozapi.registerConstant(std::move(helloDebugModeConst));
   hellozapi.registerConstant(std::move(helloPiConst));
   
   hellozapi.registerFunction<decltype(print_project_name), print_project_name>
         ("print_project_name", {
             ValueArgument("prefix", zapi::lang::Type::String)
          });
   hellozapi.registerFunction<decltype(print_develop_team), print_develop_team>
         ("print_develop_team");
   hellozapi.registerFunction<decltype(get_version), get_version>("get_version");
   hellozapi.registerFunction<decltype(add_two_num), add_two_num>
         ("add_two_num", {
             ValueArgument("num1", zapi::lang::Type::Numeric),
             ValueArgument("num2", zapi::lang::Type::Numeric)
          });
   
   Class<Person> personClass("Person");
   personClass.registerMethod<decltype(&Person::__construct), &Person::__construct>
         ("__construct", {
             ValueArgument("name", Type::String),
             ValueArgument("age", Type::Long),
             ValueArgument("address", Type::String)
          });
   personClass.registerMethod<decltype(&Person::setName), &Person::setName>
         ("setName", {
             ValueArgument("name", Type::String)
          });
   personClass.registerMethod<decltype(&Person::setAge), &Person::setAge>
         ("setAge", {
             ValueArgument("age", Type::Long)
          });
   personClass.registerMethod<decltype(&Person::setAddress), &Person::setAddress>
         ("setAddress", {
             ValueArgument("address", Type::Long)
          });
   personClass.registerMethod<decltype(&Person::getName), &Person::getName>("getName");
   personClass.registerMethod<decltype(&Person::getName), &Person::getName>("getAge");
   personClass.registerMethod<decltype(&Person::getName), &Person::getName>("getAddress");
   hellozapi.registerClass(personClass);
   
   Namespace hellozapiNs("hellozapi");
   hellozapiNs.registerConstant(Constant("DEVEL_TEAM", "qcoreteam"));
   hellozapiNs.registerConstant(Constant("RELEASE_ADDRESS", "beijing"));
   hellozapiNs.registerFunction<decltype(print_project_name), print_project_name>
       ("print_project_name", {
           ValueArgument("prefix", zapi::lang::Type::String)
       });
   hellozapiNs.registerFunction<decltype(print_develop_team), print_develop_team>
       ("print_develop_team");
   hellozapiNs.registerFunction<decltype(get_version), get_version>("get_version");
   hellozapiNs.registerFunction<decltype(add_two_num), add_two_num>
       ("add_two_num", {
           ValueArgument("num1", zapi::lang::Type::Numeric),
           ValueArgument("num2", zapi::lang::Type::Numeric)
       });
   Namespace kernelNs("kernel");
   kernelNs.registerConstant(Constant("KERNEL_VERSION", "v0.0.1"));
   kernelNs.registerFunction<decltype(print_develop_team), print_develop_team>
       ("print_develop_team");
   hellozapiNs.registerNamespace(kernelNs);
   hellozapi.registerNamespace(hellozapiNs);
   
   zapi::lang::Ini cacheDir("cache_dir", "/var/cache");
   zapi::lang::Ini expireCfg("expire_seconds", 123);
   zapi::lang::Ini enableLog("enable_log", true);
   hellozapi.registerIni(std::move(cacheDir));
   hellozapi.registerIni(std::move(expireCfg));
   hellozapi.registerIni(std::move(enableLog));
   return hellozapi;
}

}

