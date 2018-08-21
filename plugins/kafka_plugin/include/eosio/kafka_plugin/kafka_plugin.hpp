/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

#include <eosio/chain_plugin/chain_plugin.hpp>
#include <appbase/application.hpp>
#include <memory>

namespace eosio
{

using namespace appbase;

/**
 * Send topics to Kafka for:
 * accounts
 * actions
 * block_states
 * blocks
 * transaction_traces
 * transactions
 * pub_keys
 * account_controls
 *
 *   See data dictionary (DB Schema Definition - EOS API) for description of Kafka topic.
 *
 *   If cmake -DBUILD_KAFKA_PLUGIN=true  not specified then this plugin not compiled/included.
 */
class kafka_plugin : public appbase::plugin<kafka_plugin>
{
  public:
    APPBASE_PLUGIN_REQUIRES((chain_plugin))

    kafka_plugin();
    virtual ~kafka_plugin();

    virtual void set_program_options(options_description &, options_description &cfg) override;

    void plugin_initialize(const variables_map &options);
    void plugin_startup();
    void plugin_shutdown();

  private:
    std::unique_ptr<class kafka_plugin_impl> my;
};

} // namespace eosio
