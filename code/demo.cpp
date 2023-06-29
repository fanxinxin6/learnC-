//
// Created by fanxinxin on 2023/6/29.
//
#include <node.h>

namespace demo {

    using v8::FunctionCallbackInfo;
    using v8::Isolate;
    using v8::Local;
    using v8::Object;
    using v8::String;
    using v8::Value;

// C++ 函数定义
    void Add(const FunctionCallbackInfo<Value>& args) {
        Isolate* isolate = args.GetIsolate();

        // 从参数中获取两个数字
        double a = args[0].As<v8::Number>()->Value();
        double b = args[1].As<v8::Number>()->Value();

        // 计算和
        double sum = a + b;

        // 将结果转换为 V8 的数据类型
        Local<Value> result = v8::Number::New(isolate, sum);

        // 返回结果给 Node.js
        args.GetReturnValue().Set(result);
    }

// 初始化扩展模块
    void Initialize(Local<Object> exports) {
        NODE_SET_METHOD(exports, "add", Add);
    }

    NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

}  // namespace demo
