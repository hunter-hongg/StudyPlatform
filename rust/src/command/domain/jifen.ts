import { invoke } from "@tauri-apps/api/core";

export namespace domain.jifen {
    export async function get_level(inp: number): Promise<number> {
        return invoke<number>("jifen_getlevel", {jif: inp})
    }
}