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
#include "defs.h"
#include <iostream>

void print_project_name(const StringVariant &prefix)
{
   zapi::out << prefix << " " << "hellozapi" << std::flush;
}

void print_develop_team()
{
   zapi::out << "qcoreteam" << std::flush;
}

Variant get_version()
{
   return "v1.0.2";
}

Variant add_two_num(const NumericVariant &num1, const NumericVariant &num2)
{
   return num1 + num2;
}

void Person::__construct(const zapi::ds::StringVariant &name, const zapi::ds::NumericVariant &age, 
                    const zapi::ds::StringVariant &address)
{
   m_name = name.toString();
   m_age = age.toLong();
   m_address = address.toString();
}

void Person::setName(const zapi::ds::StringVariant &name)
{
   m_name = name.toString();
}

void Person::setAge(const zapi::ds::NumericVariant &age)
{
   m_age = age.toLong();
}

void Person::setAddress(const zapi::ds::StringVariant &address)
{
   m_address = address.toString();
}

Variant Person::getName()
{
   return m_name;
}

Variant Person::getAge()
{
   return m_age;
}

Variant Person::getAddress()
{
   return m_address;
}
