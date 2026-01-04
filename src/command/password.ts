import { invoke } from "@tauri-apps/api/core"

export namespace password {
    export class reader {
        ikey: string
        skey: string
        wakey: string
        constructor(i: string, s: string, wa: string) {
            this.ikey = i 
            this.skey = s 
            this.wakey = wa
        }
        async Int(): Promise<number> {
            return invoke<number>(this.ikey)
        }
        async Str(): Promise<string> {
            return invoke<string>(this.skey)
        }
        async WAdd(a: number) {
            return invoke<null>(this.wakey, {num: a})
        }
    }
    export async function jifen_reader(): Promise<reader> {
        return new reader("jifen_get_int", "jifen_get_str", "jifen_add")
    }
}