#include "GMEpicGames.h"

static std::mutex g_err_mtx;
static std::string g_last_error;

std::atomic<bool> g_eos_initialized{ false };

void eos_set_last_error(std::string_view msg)
{
    std::lock_guard<std::mutex> lock(g_err_mtx);
    g_last_error.assign(msg.data(), msg.size());
}

void eos_clear_last_error()
{
    std::lock_guard<std::mutex> lock(g_err_mtx);
    g_last_error.clear();
}

std::string eos_api_last_error()
{
    std::lock_guard<std::mutex> lock(g_err_mtx);
    return g_last_error;
}

bool eos_api_is_initialized()
{
    return g_eos_initialized.load();
}

void eos_set_initialized(bool v)
{
    g_eos_initialized.store(v);
}


static EOS_HPlatform g_eos_platform = nullptr;

EOS_HPlatform eos_platform_get()
{
    return g_eos_platform;
}

void eos_platform_set(EOS_HPlatform handle)
{
    g_eos_platform = handle;
}
