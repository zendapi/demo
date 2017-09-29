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

#ifndef ZAPI_HELLOZAPI_DEFS_H
#define ZAPI_HELLOZAPI_DEFS_H

#include "zapi/ZendApi.h"
#include <string>

using zapi::ds::Variant;
using zapi::ds::NumericVariant;
using zapi::ds::StringVariant;

void print_project_name(const StringVariant &prefix);
void print_develop_team();
Variant get_version();
Variant add_two_num(const NumericVariant &num1, const NumericVariant &num2);

class Person : public zapi::lang::StdClass
{

public:
   void __construct(const StringVariant &name, const NumericVariant &age, 
                    const StringVariant &address);
   void setName(const StringVariant &name);
   void setAge(const NumericVariant &age);
   void setAddress(const StringVariant &address);
   Variant getName();
   Variant getAge();
   Variant getAddress();
protected:
   int m_age;
   std::string m_name;
   std::string m_address;
};

#endif // ZAPI_HELLOZAPI_DEFS_H
