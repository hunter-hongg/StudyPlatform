import { invoke } from "@tauri-apps/api/core";

export namespace env {
    export async function get_user(): Promise<string> {
        try {
            let result = await invoke<string>("env_get_user");
            return result
        } catch(err) {
            // TODO: 实现错误处理逻辑
            return ""
        }
    }
}