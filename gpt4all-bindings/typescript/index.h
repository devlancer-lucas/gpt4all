#include <napi.h>
#include "llmodel.h"
#include <iostream>
#include "llmodel_c.h" 
#include "prompt.h"
#include <atomic>
#include <memory>
#include <filesystem>
namespace fs = std::filesystem;

class NodeModelWrapper: public Napi::ObjectWrap<NodeModelWrapper> {
public:
  NodeModelWrapper(const Napi::CallbackInfo &);
  //~NodeModelWrapper();
  Napi::Value getType(const Napi::CallbackInfo& info);
  Napi::Value IsModelLoaded(const Napi::CallbackInfo& info);
  Napi::Value StateSize(const Napi::CallbackInfo& info);
  /**
   * Prompting the model. This entails spawning a new thread and adding the response tokens
   * into a thread local string variable.
   */
  Napi::Value Prompt(const Napi::CallbackInfo& info);
  void SetThreadCount(const Napi::CallbackInfo& info);
  Napi::Value getName(const Napi::CallbackInfo& info);
  Napi::Value ThreadCount(const Napi::CallbackInfo& info);
  /*
   * The path that is used to search for the dynamic libraries
   */
  Napi::Value GetLibraryPath(const Napi::CallbackInfo& info);
  /**
   * Creates the LLModel class
   */
  static Napi::Function GetClass(Napi::Env);
  llmodel_model GetInference();
private:
  /**
   * The underlying inference that interfaces with the C interface
   */
  std::atomic<std::shared_ptr<llmodel_model>> inference_;

  std::string type;
  // corresponds to LLModel::name() in typescript
  std::string name;
  static Napi::FunctionReference constructor;
};
